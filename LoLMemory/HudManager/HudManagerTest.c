#include "LoLMemory/HudManager/HudManager.h"
#include "LoLClientAPI.h"

bool
HudManager_test (HudManager *hud)
{
	// get_camera_position test
	Position cameraPosition;
	get_camera_position(&cameraPosition.x, &cameraPosition.y);

	if (!Position_in_map (&cameraPosition)) {
		error ("Camera position failed : %f %f", cameraPosition.x, cameraPosition.y);
		return false;
	}

	return true;
}
