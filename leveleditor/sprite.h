#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


using namespace std;


class Sprite
{

 public:
  Sprite(string filename, int x, int y, int spriteWidth, int spriteHeight);
  ~Sprite();
  void draw();
  SDL_Rect& getRect();

 private:
  SDL_Surface *spriteSurface;

 protected:
  SDL_Rect spriteRect;
  SDL_Rect frameRect;

};


#endif
