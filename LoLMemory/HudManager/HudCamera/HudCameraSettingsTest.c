#include "HudCameraSettings.h"
#include "LoLClientAPI.h"

#define __DEBUG_OBJECT__ "HudCameraSettingsTest"
#include "dbg/dbg.h"


/*
 * Description : Unit tests checking if a HudCameraSettings is coherent
 * HudCameraSettings *this : The instance to test
 * Return : true on success, false on failure
 */
bool
HudCameraSettings_test (
	HudCameraSettings *this
) {
	if (!(this->cameraActivated == 0 || this->cameraActivated == 1)) {
		fail ("Camera activated wrong status : %d\n", this->cameraActivated);
	}

	return true;
}

