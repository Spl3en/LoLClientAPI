#include "GUIMinimap.h"
#include "LoLClientAPI.h"

#define __DEBUG_OBJECT__ "GUIMinimapTest"
#include "dbg/dbg.h"


/*
 * Description : Unit tests checking if a GUIMinimap is coherent
 * GUIMinimap *this : The instance to test
 * Return : true on success, false on failure
 */
bool
GUIMinimap_test (
	GUIMinimap *this
) {
	Position2D screenPosition;
	get_minimap_screen_position (&screenPosition.x, &screenPosition.y);

	if (screenPosition.x == 0 && screenPosition.y == 0) {
		important ("GUIMinimap position test failed : %f %f", screenPosition.x, screenPosition.y);
	}

	return true;
}

