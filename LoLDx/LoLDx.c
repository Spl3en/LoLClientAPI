#include "LoLDx.h"
#include "HookEngine/HookEngine.h"
#include "Win32Tools/Win32Tools.h"
#include "Scanner/Scanner.h"
#include "LoLServerAPI/LoLServerInterface.h"

// ---------- Debugging -------------
#define __DEBUG_OBJECT__ "LoLDx"
#include "dbg/dbg.h"

// Singleton
LoLDx *lolDx = NULL;


/*
 * Description 	: Allocate a new LoLDx structure.
 * DWORD baseAddress : Base address of the module
 * DWORD hudChatInstance : The address of hudChat
 * Return		: A pointer to an allocated LoLDx.
 */
LoLDx *
LoLDx_new (
	DWORD baseAddress,
	DWORD sizeOfModule
) {
	LoLDx *this;

	if ((this = calloc (1, sizeof(LoLDx))) == NULL)
		return NULL;

	if (!LoLDx_init (this, baseAddress, sizeOfModule)) {
		LoLDx_free (this);
		return NULL;
	}

	return this;
}


/*
 * Description : Initialize an allocated LoLDx structure.
 * LoLDx *this : An allocated LoLDx to initialize.
 * DWORD baseAddress : Base address of the module
 * DWORD hudChatInstance : The address of hudChat
 * Return : true on success, false on failure.
 */
bool
LoLDx_init (
	LoLDx *this,
	DWORD baseAddress,
	DWORD sizeOfModule
) {
	lolDx = this;

	// Initialize DirectX hook engine
	if (!(this->d3d9Hook = D3D9Hook_new (baseAddress, sizeOfModule))) {
		dbg ("D3D9Hook cannot be initialized.");
		return false;
	}

	// Hook DirectX functions
	if ((this->originalEndScene = D3D9Hook_hook (this->d3d9Hook, D3D9INDEX_EndScene, (ULONG_PTR) LoLDx_EndScene)) == NULL) {
		dbg ("Cannot hook EndScene.");
		return false;
	}

	return true;
}


/*
 * Description : Free an allocated LoLDx structure.
 * LoLDx *this : An allocated LoLDx to free.
 */
void
LoLDx_free (
	LoLDx *this
) {
	free (this);
}


/*
 * Description : Unit tests checking if a LoLDx is coherent
 * LoLDx *this : The instance to test
 * Return : true on success, false on failure
 */
bool
LoLDx_test (
	LoLDx *this
) {
	if (!this) {
		fail ("Instance is NULL");
		return false;
	}

	return true;
}


/// ===== Hooks =====
/*
 * Description : d3d9 EndScene hooked function.
 * Return : result of the original function
 */
HRESULT WINAPI
LoLDx_EndScene (
	IDirect3DDevice9 * pDevice
) {
	if (!lolDx->originalEndScene) {
		lolDx->originalEndScene = (void *) HookEngine_get_original_function ((ULONG_PTR) LoLDx_EndScene);
		if (!lolDx->originalEndScene) {
			fail ("EndScene is not correctly hooked.");
			return D3D_OK;
		}
	}

	return lolDx->originalEndScene (pDevice);
}
