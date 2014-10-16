#include "LoLProcess.h"
#include "LoLClientAPI.h"

#define __DEBUG_OBJECT__ "LolProcessTest"
#include "dbg/dbg.h"


/*
 * Description : Unit tests checking if a LoLProcess is coherent
 * LoLProcess *this : The instance to test
 * Return : true on success, false on failure
 */
bool
LoLProcess_test (
	LoLProcess *this
) {
	if (!HudManager_test (this->hudManager)) {
		dbg ("HudManager unit test failed.");
		return false;
	}

	if (!DestPos_test(this->destPos)) {
		dbg ("DestPos unit test failed.");
		return false;
	}

	return true;
}
