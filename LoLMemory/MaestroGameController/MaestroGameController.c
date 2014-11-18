#include "MaestroGameController.h"
#include "Scanner/Scanner.h"

// ---------- Debugging -------------
#define __DEBUG_OBJECT__ "MaestroGameController"
#include "dbg/dbg.h"

/*
 * Description 	: Allocate a new MaestroGameController structure.
 * Return		: A pointer to an allocated MaestroGameController.
 */
MaestroGameController *
MaestroGameController_new (
	MemProc *mp
) {
	MaestroGameController *this;

	if ((this = calloc (1, sizeof(MaestroGameController))) == NULL)
		return NULL;

	if (!MaestroGameController_init (this, mp)) {
		MaestroGameController_free (this);
		return NULL;
	}

	return this;
}



/*
 * Description : Initialize an allocated MaestroGameController structure.
 * MaestroGameController *this : An allocated MaestroGameController to initialize.
 * MemProc *mp : The target LoL process
 * Return : true on success, false on failure.
 */
bool
MaestroGameController_init (
	MaestroGameController *this,
	MemProc *mp
) {
	MemBlock *mb = NULL;
	Buffer *maestroGameControllerInstance = NULL;

	BbQueue *results = memscan_search_string (
		mp, "MaestroGameControllerStr",
		"MaestroGameControllerStruct is not yet initialized"
	);

	if (!results) {
		fail ("MaestroGameControllerStr not found.");
		return false;
	}

	if ((mb = bb_queue_pick_first (results))) {
		// MaestroGameControllerStr has been found
		dbg ("MaestroGameControllerStr found : 0x%08X", mb->addr);

		unsigned char pattern[] = {
			/*	8B0D E848895D     mov ecx, [dword ds:RiotLauncher.5D8948E8]
				85C9              test ecx, ecx
				75 3F             jne short RiotLauncher.5D74EA0C
				68 6040875D       push offset RiotLauncher.5D874060
				68 3C36875D       push offset RiotLauncher.5D87363C
				8D85 FCFBFFFF     lea eax, [ebp-404]
				68 00040000       push 400
				50                push eax
				E8 98D70000       call RiotLauncher.5D75C180 */
			'?',  '?', '?', '?', '?', '?',
			'?',  '?',
			0x75, '?',
			0x68, '_', '_', '_', '_',
			0x68, '?', '?', '?', '?',
			'?',  '?', '?', '?', '?', '?',
			0x68, '?', '?', '?', '?',
			'?',
			0xE8, '?', '?', '?', '?'
		};

		// Replace ____ with MaestroGameControllerStr address
		int replacePos = str_n_pos(pattern, "____", sizeof(pattern));
		memcpy(&pattern[replacePos], &mb->addr, 4);

		// We don't need results anymore
		bb_queue_free_all (results, memblock_free);

		// Find a reference to HudManagerAddress
		results = memscan_search (mp, "MaestroGameControllerInstance",
			pattern,

			"??????"
			"??"
			"x?"
			"xxxxx"
			"x????"
			"??????"
			"x????"
			"?"
			"x????",

			"xx????"
			"xx"
			"xx"
			"xxxxx"
			"xxxxx"
			"xxxxxx"
			"xxxxx"
			"x"
			"xxxxx"
		);

		if (results && (maestroGameControllerInstance = bb_queue_pick_first(results))) {

			return true;
		}
	}


	return true;
}



/*
 * Description : Free an allocated MaestroGameController structure.
 * MaestroGameController *this : An allocated MaestroGameController to free.
 */
void
MaestroGameController_free (
	MaestroGameController *this
) {
	if (this != NULL)
	{
		free (this);
	}
}


/*
 * Description : Unit tests checking if a MaestroGameController is coherent
 * MaestroGameController *this : The instance to test
 * Return : true on success, false on failure
 */
bool
MaestroGameController_test (
	MaestroGameController *this
) {

	return true;
}
