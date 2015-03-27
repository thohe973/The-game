#The game
This is a game created as a project in the course TDP005 at Linköping University, 2012.  
This game is created by Thomas Henriksson and Hannah Börjesson.
##Requirements
* SDL libsdl1.2-dev
* SDL_image libsdl-image1.2-dev
* SDL_ttf libsdl-ttf2.0-dev
* g++ with support for C++11
* make

##Install
Run the makefile in the game folder.


##How to play
Install the game and run 'the_game'.

####Controls
This is a co-op game. 

To move player one use arrowkeys left, right and up.  
To move player two use keys a, d and w.  
To exit to the menu press Esc.  
To retry a level press r.  

####Rules
Clouds with lightnings are deadly, clouds without are not.  
When standing on a yellow zone all the clouds changes state.  
To win the game or continue to the next level both players must stand on a green zone.  

#Leveleditor

##Requirements
* Same as the game.

##Install:
Run the makefile in the leveleditor folder.

##Use:
Install the leveleditor and run 'leveleditor'.

When prompted to open a map enter an old .map file or empty.map  
In the leveleditor use keys 0-5 to toggle tiletype.  
The white tile is used to save a x,y coordinate below the map data so you can easily add powerup, players and cloud(s) later.  
Press esc when you want to exit the leveledior.  

Open the newly saved .map file in a text editor and enter the following below the map data:  
[powerup x] [powerup y]  
[path to player1 sprite] [x] [y]  
[path to player2 sprite] [x] [y]  
[cloud x] [cloud y] [movement span] [start direction] [on/off]  
[zero or more clouds..]


##Add level to game:
Put the created *.map file in the the_game/maps folder and it to levels.lev










