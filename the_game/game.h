#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <iostream>
#include "map.h"
#include "player.h"
#include "cloud.h"
#include "powerup.h"
#include "text.h"
#include "timer.h"

/**
 * Handles "everything" in the game.
 */

class Game
{
 public:
  Game();
  ~Game();

  /**
   * Runs the game.
   */
  int run();

 private:
  void loadLevel(std::string filename);
  bool checkColl(SDL_Rect& a, SDL_Rect& b) const;
  void deleteLevel();
  
  Map *map = nullptr;
  Powerup *powerup = nullptr;
  std::vector<std::string> levels;
  std::vector<Cloud*> clouds;
  std::vector<Player*> players;

  const int SCREEN_WIDTH = 1024;
  const int SCREEN_HEIGHT = 640;
  const int FRAMES_PER_SECOND = 30;   

  bool strike;
  bool freeze = false;
  bool quit = false;
  bool levelComplete;
  bool showPowerup = true;
  Text myText;
  Timer fps;

};


#endif
