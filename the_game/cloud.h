#ifndef CLOUD_H
#define CLOUD_H

#include "sprite.h"
/**
 * A subclass from Sprite.
 */

class Cloud : public Sprite
{

 public:
  /**
   * Sets the movement, direction and if the cloud should start with a lightning.
   */
  Cloud(int x, int y, int _movement, int _dirX, bool _lightningOn);

  /**
   * Moves the cloud, depending on which value strike has the cloud shows/hides the lightning.
   */
  void move(int strike);

 private:
  int movement;
  int counter = 1;
  int dirX;
  bool lightningOn;
 
};

#endif
