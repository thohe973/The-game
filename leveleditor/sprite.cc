#include "sprite.h"
#include "SDL_image.h"

Sprite::Sprite(string filename, int x, int y, int spriteWidth, int spriteHeight)
{
  
  //Minnesläcka!
  //spriteSurface = SDL_DisplayFormat(IMG_Load(filename.c_str()));

  SDL_Surface *temp = IMG_Load(filename.c_str()); 
  spriteSurface = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  spriteRect.x = x;
  spriteRect.y = y;
  spriteRect.w = spriteSurface->w;
  spriteRect.h = spriteSurface->h;

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

  //SDL_BlitSurface(spriteSurface, NULL, screen, &spriteRect);
  SDL_BlitSurface(spriteSurface, &frameRect, screen, &spriteRect);

 
}

SDL_Rect& Sprite::getRect()
{
  return spriteRect;


}

