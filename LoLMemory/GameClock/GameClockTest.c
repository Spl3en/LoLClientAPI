#include "GameClock.h"
#include "LoLServerAPI/LoLServerInterface.h"

#define __DEBUG_OBJECT__ "GameClockTest"
#include "dbg/dbg.h"


/*
 * Description : Unit tests checking if a GameClock is coherent
 * GameClock *this : The instance to test
 * Return : true on success, false on failure
 */
bool
GameClock_test (
	GameClock *this
) {
	float gameTime = get_game_time ();

	if (gameTime <= 0.0 || gameTime >= 3600.0 * 3) {
		// 3 hours should be enough...
		return false;
	}

	return true;
}
