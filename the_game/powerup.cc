#include "powerup.h"



Powerup::Powerup(int x, int y)
  : Sprite("./sprites/powerup.png", x, y, 32, 32, true) { }


void Powerup::move(int x)
{  
  //Show next clip in animation
  if (counter % x == 0)
    {
      frameRect.x = (frameRect.x + 32 < 64 ? frameRect.x + 32 : 0);
    }
  
  ++counter;
}
