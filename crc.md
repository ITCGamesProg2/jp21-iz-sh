<h1> CRC Cards </h1>

<p>&nbsp;</p>

**Menu**
__________________________________
Allows player to start game.
Allows player to view instructions.
Allows player to exit game.
Allows player customisation.
__________________________________
Screen, Instructions, Player

<p>&nbsp;</p>

**Instructions**
__________________________________
Explains how to play the game.
__________________________________

<p>&nbsp;</p>

**Screen**
__________________________________
Drawing everything that needs to be drawn to the screen for the game to work.
__________________________________
Player, Box, AI, HUD, Bullet, Pickups

<p>&nbsp;</p>

**ScreenSize**
__________________________________
Creates global variables for width and height of the screen.
__________________________________

<p>&nbsp;</p>

**Player**
__________________________________
Player movement around screen.
Player can't move outside of screen.
Player Shooting.
Player hiding.
__________________________________
Bullet, Boxes, ScreenSize

<p>&nbsp;</p>

**Box**
__________________________________
Being destroyed by AI bullet.
Having a randomised position.
Giving player hidden status.
Blocks player from passing.
Chance to contain gun or ammo.
__________________________________
Bullet, Player, Pickups

<p>&nbsp;</p>

**AI**
__________________________________
Move to random location on screen.
Shoot at player if player is within vision cone.
Avoids going through boxes.
Calculate closet box to it and shoot at it to destroy it.
__________________________________
Player, Bullet, Box, ScreenSize

<p>&nbsp;</p>

**Bullet**
__________________________________
Generates bullet at player/AI position.
Bullet movement.
Collision detection with boxes and AI or player.
Border checking.
__________________________________
Player, AI, Box, ScreenSize

<p>&nbsp;</p>

**Pickups**
__________________________________
Gun gives player ability to shoot.
Player can shoot if they have ammo.
Check if player is close enough to pickup the gun/ammo.
__________________________________
Player

<p>&nbsp;</p>

**HUD**
__________________________________
Fetches and shows the Player hidden status.
Shows Player Health.
Shows AI Health.
Shows Ammo Stock.
Shows if gun is in player's possession.
__________________________________
Player, AI, Box
