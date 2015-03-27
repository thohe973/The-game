#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

/**
 * The superclass.
 * Loads, draws, moves the sprite.
 */

class Sprite
{

 public:
  /**
   * Loads the given image, sets x and y and how large the sprite is.
   * If tile is true x and y are multiplied by 32.
   */
  Sprite(std::string filename, int x, int y, int spriteWidth, int spriteHeight, bool tile);

  /**
   * Releases the loaded png.
   */
  virtual ~Sprite();

  /**
   * Draws the sprite.
   */
  void draw();

  /**
   * Abstract function for implentation in subclasses.
   */
  virtual void move(int x) = 0;

  /**
   * Returns a SDL_Rect containing the sprites x,y,w,h.
   */
  SDL_Rect& getRect();

 private:
  SDL_Surface *spriteSurface;

 protected:
  SDL_Rect spriteRect;
  SDL_Rect frameRect;

};


#endif
