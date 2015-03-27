#ifndef POWERUP_H
#define POWERUP_H

#include "sprite.h"

/**
 * The powerup.
 */

class Powerup : public Sprite
{
  public:

  /**
   * Sets the position.
   */
  Powerup(int x, int y);

  /**
   * *Doesnt really move*
   * Handles the animation of the powerup
   */
  void move(int x);

 private:
  int counter = 0;

};

#endif
