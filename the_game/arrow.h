#ifndef ARROW_H
#define ARROW_H

#include "sprite.h"

/**
 * A subclass from sprite.
 */

class Arrow : public Sprite 
{
 public:
  Arrow();

  /**
   * Moves the arrow in the main-menu.
   */
  void move(int y);
  
}; 

#endif
