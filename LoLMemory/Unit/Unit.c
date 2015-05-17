#include "Unit.h"
#include <stdlib.h>

// ---------- Debugging -------------
#define __DEBUG_OBJECT__ "Unit"
#include "dbg/dbg.h"

/*
 * Description 	: Allocate a new Unit structure.
 * DWORD pUnit  : The address of the Unit in the target process
 * Return       : A pointer to an allocated Unit.
 */
Unit *
Unit_new (
	DWORD pUnit
) {
	Unit *this;

	if ((this = calloc (1, sizeof(Unit))) == NULL)
		return NULL;

	if (!Unit_init (this, pUnit)) {
		Unit_free (this);
		return NULL;
	}

	return this;
}


/*
 * Description  : Initialize an allocated Unit structure.
 * Unit *this   : An allocated Unit to initialize.
 * DWORD pUnit  : The address of the Unit in the target process
 * Return       : true on success, false on failure.
 */
bool
Unit_init (
	Unit *this,
	DWORD pUnit
) {
	DWORD pThis = *((DWORD *) pUnit);

	if (pThis != 0) {
		memcpy (this, *((DWORD **) pUnit), sizeof(Unit));
	}

	this->pThis = pThis;
	this->thisStatic = pUnit;
	this->teammateId = -1;

	if (pThis == 0) {
		dbg ("Unit not initialized.");
		// We return true because we might want to keep thisStatic variable
		// even if the unit is not initliazed
		return true;
	}

	// Fix <address><Object> reference summoner name
	if (strcmp(&this->summonerName[4], "Object") == 0) {
		// Rare case when the summoner name is actually <sname{1...3}><\0><Object>
		if (this->summonerName[0] != 0
		 && this->summonerName[1] != 0
		 && this->summonerName[2] != 0
		 && this->summonerName[3] != 0) {
			DWORD summonerNameAddress;
			memcpy (&summonerNameAddress, this->summonerName, 4);
			memcpy (this->summonerName, (DWORD *) summonerNameAddress, sizeof(this->summonerName));
		}
	}

	if (this->pThis) {
		dbg ("Unit <%.16s> detected. (0x%08X)", this->summonerName, pUnit);
	} else {
		warning ("Unit <0x%08X> not found.", pUnit);
	}

	return true;
}


/*
 * Description : Free an allocated Unit structure.
 * Unit *this  : An allocated Unit to free.
 */
void
Unit_free (
	Unit *this
) {
	if (this != NULL)
	{
		free (this);
	}
}
