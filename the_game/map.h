#ifndef MAP_H
#define MAP_H
#include <vector>
#include <iostream>
#include "sprite.h"

/**
 * Handles map-data.
 */

class Map
{

 public:

  /**
   * Loads the given level-file.
   */
  Map(std::string filename);
  ~Map();
   
  /**
   * Returns the number in mapVector at x,y.
   */
  int getXY(int x, int y);
 
  /**
   * Draws the map.
   */
  void draw();


  /**
   * Used for debugging.
   */
  void print();

 private:  
  SDL_Surface* loadImage(std::string filename);

  std::vector <std::vector<int> > mapVector;
  std::vector <SDL_Surface*> tiles;
  SDL_Rect tileRect;

  //Screenwidth, width/tilesize (1024/32)
  const int MAP_WIDTH = 32;   
  //Screenheight, height/tilesize (640/32)
  const int MAP_HEIGHT = 20;

};


#endif
