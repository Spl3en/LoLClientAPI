import LoLClientAPI
import time
from datetime import datetime
import win32con

class PyLoLCamera:

	# ======= Configurations ========
	threshold   = 300.0
	cameraSpeed = 2
	cameraScrollSpeedBottom = 1.5
	sleepSecondsAfterMinimapClick = 3
	toggleLoLCameraKey = win32con.VK_F11
	
	# Temporary fix
	minimapX = 1600
	minimapY = 900

	# Weights
	championWeight = 1.0
	cursorWeight   = 2.0

	def __init__ (self):
		# ===== Start of the program ======
		# Inject LoLClientAPI in LoLProcess
		self.api = LoLClientAPI.LoLClientAPI ();

		# Disable default client camera behavior
		# (so the camera doesn't move when the cursor reaches the border of the screen)
		self.api.set_default_camera_enabled (False);

		# Start the main loop
		self.run ();

	def run (self):
	
		self.running = True;

		# Get the current camera position
		cameraX, cameraY = self.api.get_camera_position ();

		# Program infinite loop
		while (1):

			# Sleep during 1 millisecond so the script doesn't take 100% CPU
			time.sleep (0.001);
			
			# Check toggle key
			if self.api.is_key_typed (self.toggleLoLCameraKey):
				self.running = not self.running;

			# Check if LoLCamera is running
			if not self.running:
				continue;
				
			cursorScreenX, cursorScreenY = self.api.get_cursor_screen_position ();
				
			# Don't do anything if the cursor is hovering the minimap
			# if self.api.is_cursor_hovering_minimap ():
			if cursorScreenX > self.minimapX and cursorScreenY > self.minimapY:
				# Handle the event and go back to sleep
				self.hover_minimap_behavior (cameraX, cameraY);
				continue;

			# Get game objects position
			cursorX, cursorY = self.api.get_cursor_position ();
			cameraX, cameraY = self.api.get_camera_position ();
			championX, championY = self.api.get_champion_position ();

			# Fix perspective : Move the camera farther to the bottom of the screen
			# than to the top of the screen http://i.imgur.com/cwpZk3Z.png
			distanceMouseCamY = cameraY - cursorY;
			if (distanceMouseCamY > self.threshold):
				# If the cursor is in the bottom part of the screen (positive value) and superior to threshold value
				# Decrease slightly the cursorY position so it simulates a farther bottom scrolling
				cursorY -= (distanceMouseCamY * self.cameraScrollSpeedBottom);

			# Sum all the weights
			sumWeights = self.championWeight + self.cursorWeight;

			# Compute the weighted target position : Between the cursor and the champion
			# http://puu.sh/cAWUw/c703c6233c.png
			targetX = (championX * self.championWeight + cursorX * self.cursorWeight) / sumWeights;
			targetY = (championY * self.championWeight + cursorY * self.cursorWeight) / sumWeights;

			# Smoothing : We don't want the camera to jump to the target position too quickly
			# Increase the camera position value slowly if it's greater than "threshold" value
			if (abs (targetX - cameraX) > self.threshold):
				cameraX += ((targetX - cameraX) * 0.001) * self.cameraSpeed;

			if (abs (targetY - cameraY) > self.threshold):
				cameraY += ((targetY - cameraY) * 0.001) * self.cameraSpeed;

			# Update the new camera position
			self.api.set_camera_position (cameraX, cameraY);

			
	def hover_minimap_behavior (self, cameraX, cameraY) :

		# If a mouse click is detected, sleep a little
		if (self.api.is_left_mouse_button_click ()):
			timeStartSleeping = datetime.now ();

			# Sleep until sleepSecondsAfterMinimapClick seconds has passed, or space is pressed
			while (datetime.now () - timeStartSleeping).total_seconds() <= self.sleepSecondsAfterMinimapClick:
				time.sleep (0.001);

				if (self.api.is_key_pressed (win32con.VK_SPACE)):
					# Space has been pressed during the sleeping, exit the loop
					break;

			# Restore the camera position to the champion position
			championX, championY = self.api.get_champion_position ();
			self.api.set_camera_position (championX, championY);
		
if __name__ == '__main__':
	PyLoLCamera ();
