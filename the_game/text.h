#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"

/**
 * Draws text and boxes on the screen.
 */

class Text
{

 public:
  Text();
  ~Text();

  /**
   * Draws the given text at the given position.
   */
  void drawText(int x, int y, std::string text);

  /**
   * Draws a box at the given position with the given dimensions.
   */
  void drawBox(int x, int y, int w, int h);

 private:
  SDL_Rect textRect; 
  SDL_Rect fillRect;
  SDL_Surface *textSurface;
  TTF_Font *font;
  SDL_Color textColor {0, 0, 0, 0};

};

#endif
