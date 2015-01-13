#include "LoLAPIRequest.h"
#include <stdlib.h>

// ---------- Debugging -------------
#define __DEBUG_OBJECT__ "LoLAPIRequest"
#include "dbg/dbg.h"

static EnumerationStringAssociation association [REQUEST_API_COUNT] = {

	[0 ... REQUEST_API_COUNT-1] = {REQUEST_UNDEFINED, "REQUEST_UNDEFINED"},

	// Camera APIs
	associate (REQUEST_GET_CAMERA_POSITION),
	associate (REQUEST_SET_CAMERA_POSITION),
	associate (REQUEST_SET_DEFAULT_CAMERA_ENABLED),
	associate (REQUEST_GET_CAMERA_ANGLE),
	associate (REQUEST_SET_CAMERA_ANGLE),
	associate (REQUEST_GET_CAMERA_ZOOM),
	associate (REQUEST_SET_CAMERA_ZOOM),

	// Cursor APIs
	associate (REQUEST_GET_CURSOR_POSITION),
	associate (REQUEST_GET_CURSOR_SCREEN_POSITION),
	associate (REQUEST_GET_DESTINATION_POSITION),
	associate (REQUEST_IS_LEFT_MOUSE_BUTTON_PRESSED),
	associate (REQUEST_IS_LEFT_MOUSE_BUTTON_CLICK),
	associate (REQUEST_IS_RIGHT_MOUSE_BUTTON_PRESSED),
	associate (REQUEST_IS_RIGHT_MOUSE_BUTTON_CLICK),

	// Keyboard APIs
	associate (REQUEST_IS_KEY_PRESSED),
	associate (REQUEST_IS_KEY_TYPED),

	// Champion APIs
	associate (REQUEST_GET_CHAMPION_POSITION),
	associate (REQUEST_GET_CHAMPION_HP),
	associate (REQUEST_GET_CHAMPION_TEAM),

	// Teammates APIs
	associate (REQUEST_GET_TEAMMATES_COUNT),
	associate (REQUEST_CHECK_TEAMMATE_ID),
	associate (REQUEST_GET_TEAMMATE_POSITION),
	associate (REQUEST_GET_TEAMMATE_HP),
	associate (REQUEST_GET_TEAMMATE_SUMMONER_NAME),

	// Minimap APIs
	associate (REQUEST_GET_MINIMAP_SCREEN_POSITION),
	associate (REQUEST_IS_CURSOR_HOVERING_MINIMAP),

	// Summoner APIs
	associate (REQUEST_GET_CURRENT_SUMMONER_NAME),

	// Game APIs
	associate (REQUEST_GET_GAME_TIME),

	// Chat APIs
	associate (REQUEST_GET_CHAT_MESSAGE),
	associate (REQUEST_LOG_CHAT_MESSAGE),

	// Drawing APIs
	associate (REQUEST_CREATE_RECTANGLE),
	associate (REQUEST_CREATE_TEXT),
	associate (REQUEST_CREATE_SPRITE),
	associate (REQUEST_DELETE_OBJECT),
	associate (REQUEST_DELETE_ALL_OBJECTS),
	associate (REQUEST_SHOW_OBJECT),
	associate (REQUEST_SHOW_ALL_OBJECTS),
	associate (REQUEST_HIDE_OBJECT),
	associate (REQUEST_HIDE_ALL_OBJECTS),
	associate (REQUEST_MOVE_OBJECT),
	associate (REQUEST_TEXT_OBJECT_SET),

	// Internal APIs
	associate (REQUEST_EJECT_API),

	// Error status
	associate (REQUEST_FAIL)
};

/*
 * Description           : Check if a LoLAPIRequest is valid
 * LoLAPIRequest *this   : An allocated LoLAPIRequest
 * Return                : bool true on success, false otherwise
 */
bool
LoLAPIRequest_is_valid (
	LoLAPIRequest request
) {
	return (request < REQUEST_API_COUNT
		 && request >= 0);
}

/*
 * Description           : Convert a LoLAPIRequest to string
 * LoLAPIRequest request : The LoLApiRequest to convert
 * Return                : char * the string
 */
char *
LoLAPIRequest_to_string (
	LoLAPIRequest request
) {
	if (!LoLAPIRequest_is_valid (request)) {
		return NULL;
	}

	return association[request].string;
}
