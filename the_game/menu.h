#ifndef MENU_H
#define MENU_H

#include "sprite.h"
#include "text.h"

/**
 * The menu-class.
 */

class Menu 
{
 public:
  Menu();
  ~Menu();

  /**
   * Displays the menu and handles input from user.
   */
  void run();

 private:
  const int SCREEN_WIDTH = 1024;
  const int SCREEN_HEIGHT = 640;
  SDL_Surface *screen = nullptr;
  int current = 1;

  bool quit = false;
  Text myText;

};

#endif
