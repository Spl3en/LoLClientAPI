#include "ChampionArray.h"
#include "LoLServerAPI/LoLServerInterface.h"

#define __DEBUG_OBJECT__ "ChampionArrayTest"
#include "dbg/dbg.h"


/*
 * Description         : Unit tests checking if a ChampionArray is coherent
 * ChampionArray *this : The instance to test
 * Return              : true on success, false on failure
 */
bool
ChampionArray_test (
	ChampionArray *this
) {
	if (!this) {
		error ("Instance is NULL");
		return false;
	}

	if (this->end == 0 || this->start == 0) {
		error ("ChampionArray boundaries is egal to zero, test failed.");
		return false;
	}

	if (this->end < this->start) {
		error ("Wrong championArray boundaries, test failed.");
		return false;
	}

	if (this->championsCount > 12) {
		error ("The number of champions seems a bit weird : %d players.", this->championsCount);
		// Don't fail : Who knows if Riot will release a 16 players game mode someday.
	}

	for (int i = 0; i < this->championsCount; i++)
	{
		if (! Unit_test (this->champions[i])) {
			error ("Unit test Unit ID=%d failed.", i);
			return false;
		}
		dbg ("[OK] Unit <%.16s> test success.", this->champions[i]->summonerName);
	}

	return true;
}
