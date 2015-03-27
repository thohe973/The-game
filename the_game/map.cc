#include "map.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Map::Map(string filename)
{

  ifstream file(filename);
  
  for (int y = 0; y < MAP_HEIGHT; ++y)
    {      
      mapVector.push_back(vector<int>());

      for (int x = 0; x < MAP_WIDTH; ++x)
	{
	  mapVector[y].push_back(0);
	  file >> mapVector[y][x];
	}
    }

  tiles.push_back(loadImage("./sprites/0.png"));
  tiles.push_back(loadImage("./sprites/1.png"));
  tiles.push_back(loadImage("./sprites/2.png"));
  tiles.push_back(loadImage("./sprites/3.png"));
  tiles.push_back(loadImage("./sprites/4.png")); 
  
}

Map::~Map()
{
  for(SDL_Surface*& tile : tiles)
    {
      SDL_FreeSurface(tile);
    }
}


void Map::draw()
{

  SDL_Surface* screen = SDL_GetVideoSurface();

  for (unsigned y = 0; y < mapVector.size(); ++y)
    {     
      tileRect.y = y*32;
      
      for (unsigned x = 0; x < mapVector[y].size(); x++)
	{	  
	  tileRect.x = x*32;	  
	  SDL_BlitSurface(tiles[mapVector[y][x]], NULL, screen, &tileRect);	  
	}
    }
}

int Map::getXY(int x, int y)
{

  // if (x < 0 || y < 0 || y > 640 || x > 1024)
  //   {
  //     return 99; 
  //   }

  return mapVector[y][x];
}

SDL_Surface* Map::loadImage(string filename)
{
    SDL_Surface* temp = NULL;
    SDL_Surface* optimizedImage = NULL;

    temp = IMG_Load(filename.c_str());
    optimizedImage = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    
    return optimizedImage;
}



//--------------DEBUGGING--------------------------------

void Map::print()
{

 for (unsigned i = 0; i < mapVector.size(); ++i)
    {
      for (unsigned j = 0; j < mapVector[i].size(); j++)
	{
	  cout << mapVector[i][j] << " ";
	}
      cout << endl;
    }

}
