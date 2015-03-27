#include "cloud.h"


Cloud::Cloud(int x, int y, int _movement, int _dirX, bool _lightningOn)
  : Sprite("./sprites/cloud.png", x, y, 64, 160, true)
{
  dirX = _dirX;
  lightningOn = _lightningOn;
  movement = _movement*32;  
}

void Cloud::move(int strike)
{

  //Show next clip
  if (counter % 4 == 0)
    {
      frameRect.x = (frameRect.x + 64 < 192 ? frameRect.x + 64 : 0);
    }

  //Cloud should only move if movement is set
  if (movement != 0)
    {

      //Check when cloud should turn
      if (counter % movement == 0)
	{
	  dirX = -dirX;
	}

      spriteRect.x += dirX;     
     
    }

  ++counter;  

  //Check if the cloud should strike or not
  if (strike != lightningOn)    
    {
      frameRect.h = 160;
    }      
  else
    {
      frameRect.h = 32;
    }
  
}
