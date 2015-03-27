#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"
#include "map.h"
#include <iostream>

/**
 * Handles player.
 */

class Player : public Sprite
{
 public:

  /**
   * Sets the appearance and position.
   */
  Player(std::string filename, int x, int y);

  /**
   * Moves the player in the direction given by xVel. Also checks collision against map.
   */
  void move(int xVel);

  /**
   * Constantly draws the player to the ground if he doesnt jump.
   */
  void gravity();

  /**
   * Sets the map the player currently is on.
   */
  void setMap(Map*& _map);

  /**
   * Makes the player jump.
   */
  void jump();

  /**
   * Returns true if the player is standing on a green zone, false if not.
   */
  bool getGreen();
  
  /**
   * Returns true if the player is standing on a yellow zone, false if not.
   */
  bool getYellow();

  /**
   * Resets the players position and some bools.
   */
  void reset();
  
  /**
   * Sets how high the player can jump.
   */
  void setJumpSpeed(int speed);

 private:
  bool collWall(int x, int y);
  bool inAir = true;
  bool onYellow = false;
  bool onGreen = false;
  
  int jumpSpeed = -21;
  int yVel = 16;
  int rtileY, rtileX, ltileY, ltileX, startX, startY;

  int counter = 0;
  
  Map *map;

};


#endif
