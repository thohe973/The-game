#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string filename, int x, int y)
  : Sprite(filename, x, y, 32, 32, true)
{
  startX = x;
  startY = y;
}

void Player::move(int xVel)
{
  //Show next clip in animation
  if (counter % 2 == 0)
    {
      frameRect.x = (frameRect.x + 32 < 256 ? frameRect.x + 32 : 0);
    }

  //Calculate which tiles the players at x-axis
  ltileX = (spriteRect.x + xVel) / 32;
  ltileY = (spriteRect.y) / 32;
  rtileX = (spriteRect.x + xVel + spriteRect.w) / 32;
  rtileY = (spriteRect.y) / 32;


  //No collision, move player
  if ( !collWall(ltileX,ltileY) &&  !collWall(rtileX,rtileY) )
    {  
      spriteRect.x += xVel;
    }
  //Collision! move the player right next to the tile
  else
    {
      if (xVel > 0)
	{
	  spriteRect.x = (rtileX-1)*32;
	}
      else
	{
	  spriteRect.x = (ltileX+1)*32;
	}
    }

  ++counter;
}


void Player::gravity()
{   

  //Increases the yVel during jump 
  if (yVel <=  16)
    {
      yVel = yVel+2; 
    }
   
  //Calculate which tiles the players at y-axis
  rtileY = (spriteRect.y + yVel + spriteRect.h) / 32; 
  ltileY = (spriteRect.y + yVel + spriteRect.h) / 32;  
  rtileX = (spriteRect.x) / 32;
  ltileX = (spriteRect.x + spriteRect.w - 1) / 32;
  
  //If player jumps
  if (inAir && yVel <= 0)
    {
      rtileY = (spriteRect.y + yVel) / 32; 
      ltileY = (spriteRect.y + yVel) / 32;  
    }


  //If no collision
  if (!collWall(ltileX,ltileY) && !collWall(rtileX,rtileY) )
    {
      spriteRect.y += yVel;
      inAir = true;
    }
  else
    {
      //Collision with floor
      if (yVel > 0)
	{
	  spriteRect.y = (rtileY-1)*32;
	  inAir = false;;
	}
      //Collision with roof
      else
	{
	  spriteRect.y = (rtileY+1)*32;
	  yVel = 5;
	}     
    }      
}

void Player::jump()
{
  if (!inAir)
    {
      yVel = jumpSpeed;
      inAir = true;
      onYellow = false;
      onGreen = false;
    }
}

void Player::setMap(Map*& _map) 
{
  map = _map;
}

bool Player::getGreen()
{
  return onGreen;
}

bool Player::getYellow()
{
  return onYellow;
}

void Player::reset()
{
  spriteRect.x = startX*32-32;
  spriteRect.y = startY*32-32;
  onYellow = false;
  onGreen = false;
  jumpSpeed = -21;
}
  
void Player::setJumpSpeed(int speed)
{
  jumpSpeed = speed;
}


//--------------------------Private-functions-------------

bool Player::collWall(int x, int y)
{

  //If the player somehow gets out of the map, reset him. 
  if (x < 0 || x > 31 || y < 0 || y > 19 )
    {
      this->reset();
      return true;
    }

  int XY = map->getXY(x,y);

  if (XY == 3 && !inAir)
    {   
      onYellow = true;
    }

  if (XY == 4 && !inAir)
    {
      onGreen = true;
    }

  if (XY == 1)
    {
      onYellow = false;
      onGreen = false;
    }

  if (XY == 0 && inAir)
    {
      onYellow = false;
      onGreen = false;
    }

  if (XY == 0)
    {   
      return false;
    }
  else
    {
      return true;
    }

}
