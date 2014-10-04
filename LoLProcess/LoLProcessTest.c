#include "LoLProcess.h"
#include <stdlib.h>


/**
 * Description : Unit tests checking if the LoLProcess is correct
 * Return : true on success, false on failure
 */
bool
LoLProcess_test (
	LoLProcess *this
) {
	if (!HudManager_test (this->hud)) {
		return false;
	}

	return true;
}
