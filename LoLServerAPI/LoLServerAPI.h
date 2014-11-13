// --- Author : Moreau Cyril - Spl3en
#pragma once

// ---------- Includes ------------
#include "Utils/Utils.h"
#include "EasySocket/EasySocket.h"
#include "LoLProcess/LoLProcess.h"
#include "LoLAPI/LoLAPI.h"
#include "LoLAPI/LoLAPIPacket.h"
#include "LoLAPI/LoLAPIRequest.h"

// ---------- Defines -------------

// ------ Structure declaration -------
typedef struct _LoLServerAPI
{
	EasySocket * serverSocket;
	bool closed;

}	LoLServerAPI;


// --------- Allocators ---------

/*
 * Description 	: Allocate a new LoLServerAPI structure.
 * Return		: A pointer to an allocated LoLServerAPI.
 */
LoLServerAPI *
LoLServerAPI_new (void);

// ----------- Functions ------------

/*
 * Description : Initialize an allocated LoLServerAPI structure.
 * LoLServerAPI *this : An allocated LoLServerAPI to initialize.
 */
bool
LoLServerAPI_init (
	LoLServerAPI *this
);

/*
 * Description : Main loop of the API server
 * LoLServerAPI *this : An allocated LoLServerAPI
 * Return : void
 */
void
LoLServerAPI_main (
	LoLServerAPI *this
);

/*
 * Description : Unit tests checking if a LoLServerAPI is coherent
 * LoLServerAPI *this : The instance to test
 * Return : true on success, false on failure
 */
bool
LoLServerAPI_test (
	LoLServerAPI *this
);

// --------- Destructors ----------

/*
 * Description : Free an allocated LoLServerAPI structure.
 * LoLServerAPI *this : An allocated LoLServerAPI to free.
 */
void
LoLServerAPI_free (
	LoLServerAPI *this
);
