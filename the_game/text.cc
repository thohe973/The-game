#include "text.h"
#include <iostream>

using namespace std;

Text::Text()
{
  TTF_Init();
  font = TTF_OpenFont("./fonts/light.otf", 60);
}

Text::~Text()
{
  TTF_CloseFont(font);
  TTF_Quit();
}

void Text::drawText(int x, int y, string text)
{

  SDL_Surface* screen = SDL_GetVideoSurface();
  
  textRect.x = x;
  textRect.y = y;

  textSurface = TTF_RenderText_Blended(font, text.c_str(), textColor);

  SDL_BlitSurface(textSurface, NULL, screen, &textRect);

  SDL_FreeSurface(textSurface);
}

void Text::drawBox(int x, int y, int w, int h)
{

 SDL_Surface* screen = SDL_GetVideoSurface();

 fillRect.x = x;
 fillRect.y = y;
 fillRect.w = w;
 fillRect.h = h;

 SDL_FillRect(screen, &fillRect, 0xFFFFFF);

}
