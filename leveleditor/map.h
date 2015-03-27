#ifndef MAP_H
#define MAP_H
#include <vector>

#include "sprite.h"

class Map
{

 public:
  Map(string filename);
  ~Map();
   
  //Get the number in mapVector at x,y
  int getXY(int x, int y);
  void setXY(int x, int y, int value);
  void save(string filename);
  void drawTile(int x, int y, int tile);
  
  void draw();


  //Debuggning
  void print();

 private:  
  SDL_Surface* loadImage(string filename);

  vector <vector<int> > mapVector;
  vector <SDL_Surface*> tiles;
  SDL_Rect tileRect;
  SDL_Surface* grid;
  string startPosData = "";

  //Screenwidth, 1024 / tilesize, 32
  int MAP_WIDTH = 32; 
  
  //Screenheight, 640 / tilesize, 32
  int MAP_HEIGHT = 20;

};


#endif
