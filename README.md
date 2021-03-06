LoLClientAPI
============

![!](http://i.cubeupload.com/ZIhUa4.png) Disclaimer
------------


Until a Red comments otherwise, using this tool may run the risk of the punishment from Riot ![Riot](http://i.cubeupload.com/RzwjJW.gif)  
EULA infringement, section III E :  

> Use any unauthorized third-party programs that interact with the Software in any way, 
    including but not limited to, “mods,” “hacks,” “cheats,” “scripts,” “bots,” “trainers,” 
    or automation programs, or any third-party programs that intercept, emulate or redirect 
    any communication between the Software and Riot Games, or that collect information about 
    the Game by reading areas of memory used by the Software to store information about the Game.

**Use this tool at your own risk.**


![?](http://i.cubeupload.com/AJ6uDr.gif) Presentation
------------

LoLClientAPI is a project for pulling interesting values from the LoL game client.
Its goal is to provide to players a tool for exploiting data pulled from their client, and manipulate them for their own usage.

The APIs provided shouldn't help too much for botting and cheating in the game.
Thus, you can't control your champion, unzoom farther than possible or use items with this API.


![?](http://i.cubeupload.com/2md2lj.png) Installation
------------

- Download the last Beta version of LoLClientAPI.zip here : https://github.com/Spl3en/LoLClientAPI/releases Extract this archive wherever you want, e.g. on the Desktop.

- Download Python 2.7.x and install it :
    Important : Check "Add python.exe to Path" during the installation (so it is easier to launch PyLoLCamera) :
    https://www.python.org/ftp/python/2.7.8/python-2.7.8.msi

- Download and install pywin32, a module for Python : http://sourceforge.net/projects/pywin32/files/pywin32/Build%20219/pywin32-219.win32-py2.7.exe/download


- It should recognize automatically your Python folder in the registry if everything went well. At this point, optionnally you may need to restart your computer because of your new Python environnement. Once it is done, go back to the folder where you extracted LoLClientAPI.zip

- You should be able to launch "Launch PyLoLCamera.bat" during a game. If you launch it outside of the game, it's not a big deal but it just doesn't do anything until you restart it during the game.

- If you want to launch another script, copy paste Launch PyLoLCamera.bat, edit it and change the script name.


:arrow_right: Available APIs
------------
If you want to take a closer look at the prototypes, all the available APIs are exported in the [LoLClientInterface header](https://github.com/Spl3en/LoLClientAPI/blob/master/LoLClientAPI/LoLClientInterface.h).

##### Camera APIs

API Prototype | Description
-------- | -------------
```get_camera_position``` | Retrieve the current camera position  
```set_camera_position``` | Set the current camera position
```set_default_camera_enabled``` | Toggle the built-in client camera movements
```get_camera_angle``` | Retrieve the current camera angle in degrees
```set_camera_angle``` | Set the current camera angle in degrees
```get_camera_zoom``` | Retrieve the current camera zoom value
```set_camera_zoom``` | Set the current camera zoom (500.0 min, 2000.0 max)

##### Cursor APIs
API Prototype | Description
-------- | -------------
```get_cursor_position``` | Retrieve the current cursor position
```get_cursor_screen_position``` | Retrieve the position of the cursor on the screen
```get_destination_position``` | Retrieve the destination position (right click)
```is_left_mouse_button_pressed``` | Check if the left mouse button is pressed
```is_left_mouse_button_click``` | Check if the left mouse button is clicked
```is_right_mouse_button_pressed``` | Check if the right mouse button is pressed
```is_right_mouse_button_click``` | Check if the right mouse button is clicked

##### Keyboard APIs
API Prototype | Description
-------- | -------------
```is_space_pressed``` | Check if the space key is pressed

##### Champions APIs
API Prototype | Description
-------- | -------------
```get_champion_position``` | Retrieve the current champion position
```get_champion_hp``` | Retrieve current champion health points information
```get_champion_team``` | Retrieve the current champion team
```get_teammates_count``` | Retrieve the number of allies
```get_teammate_position``` | Retrieve the teammate champion position
```get_teammate_hp``` | Retrieve teammate champion health points information
```get_teammate_summoner_name``` | Retrieve teammate summoner name
```check_teammate_id``` | Check if the target teammate ID is valid. You shouldn't need to call this.

##### GUI APIs
API Prototype | Description
-------- | -------------
```get_minimap_screen_position``` | Retrieve the position of the minimap on the screen
```is_cursor_hovering_minimap``` | Check if the mouse is hovering the minimap

##### Summoner APIs
API Prototype | Description
-------- | -------------
```get_current_summoner_name``` | Retrieve the current summoner name

##### Game APIs
API Prototype | Description
-------- | -------------
```get_game_time``` | Get the current game time (as seconds)

##### Chat APIs
API Prototype | Description
-------- | -------------
```get_chat_message``` | Get the next line of the chat received since the last time called
```log_chat_message``` | Log a message to the HudChat (only for you)
    
##### Drawing APIs
API Prototype | Description
-------- | -------------
```create_rectangle``` | Create a new colored rectangle object displayed on the screen.
```create_sprite``` | Create a new sprite object displayed on the screen
```create_text``` | Create a new colored text object displayed on the screen
```move_object``` | Change the position of the object on the screen.
```rect_object_set``` | Change the attributes of the rectangle object.
```text_object_set``` | Change the attributes of the text object.
```sprite_object_set``` | Change the attributes of the sprite object.
```show_object``` | Show a hidden object. If it wasn't hidden, put it to the foreground.
```show_all_objects``` | Show all hidden objects. Don't do anything with those already shown.
```hide_object``` | Hide a visible object. It isn't deleted, so you can use `show_object` if you want to make it appear again.
```hide_all_objects``` | Hide all objects. Don't do anything with those already hidden.
```delete_object``` | Delete a specific object on the screen
```delete_all_objects``` | Delete all the previously created objects on the screen
```get_hovered_object``` | Return the object hovered by the mouse, or INVALID_OBJECT_HANDLE if no object is hovered

    
##### Internal APIs
API Prototype | Description
-------- | -------------
```eject_api``` | Eject the API from the LoL process
```get_last_error``` | Get the last error returned by the API.
```set_api_ready``` | Set a new client api and initialize it to a ready state
```check_api``` | Wait for the API to be in a ready state
    
![?](http://i.cubeupload.com/UvkfRQ.png) Internal representation of LoLClientAPI system
------------
![LoLClientAPI Overview](http://i.cubeupload.com/V9fuUE.png)

:+1: Credits
-------------

* Daniel Pistelli - Hook Engine : http://www.codeproject.com/Articles/21414/Powerful-x-x-Mini-Hook-Engine
* DLL injector : https://code.google.com/p/injector/
