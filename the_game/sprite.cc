#include "sprite.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;

Sprite::Sprite(string filename, int x, int y, int spriteWidth, int spriteHeight, bool tile)
{ 
  
  //Optimizes the given png
  SDL_Surface *temp = IMG_Load(filename.c_str());
  spriteSurface = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  //Sets the colorkey
  Uint32 colorkey = SDL_MapRGB(spriteSurface->format, 255, 0, 255);
  SDL_SetColorKey(spriteSurface, SDL_SRCCOLORKEY|SDL_RLEACCEL, colorkey);

  
  //Calculate the startposition
  if (tile)
    {
      spriteRect.x = x*32-32;
      spriteRect.y = y*32-32;
    }
  else
    {
      spriteRect.x = x;
      spriteRect.y = y;
    }

  spriteRect.w = spriteSurface->w;
  spriteRect.h = spriteSurface->h;

  //How big the sprite is in the spritesheet
  frameRect.w = spriteWidth;
  frameRect.h = spriteHeight;

  frameRect.y = 0;
  frameRect.x = 0;

}


Sprite::~Sprite()
{
  SDL_FreeSurface(spriteSurface);
}


void Sprite::draw()
{  
  SDL_Surface* screen = SDL_GetVideoSurface();
  SDL_BlitSurface(spriteSurface, &frameRect, screen, &spriteRect); 
}

SDL_Rect& Sprite::getRect()
{
  return spriteRect;
}

