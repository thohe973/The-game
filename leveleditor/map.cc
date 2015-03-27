#include "map.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Map::Map(string filename)
{

  ifstream file(filename);
  
  if (!file.is_open()) 
    {
      file.open("./empty.map");
    }
  
  for (int y = 0; y < MAP_HEIGHT; ++y)
    {      
      mapVector.push_back(vector<int>());
      
      for (int x = 0; x < MAP_WIDTH; ++x)
	{
	  mapVector[y].push_back(0);
	  file >> mapVector[y][x];
	}
    }

  //Save data below leveldata
  string temp;
  while(getline(file,temp,'\n'))
    startPosData += temp + '\n';
  


  tiles.push_back(loadImage("./sprites/0.png"));
  tiles.push_back(loadImage("./sprites/1.png"));
  tiles.push_back(loadImage("./sprites/2.png"));
  tiles.push_back(loadImage("./sprites/3.png"));
  tiles.push_back(loadImage("./sprites/4.png"));
  tiles.push_back(loadImage("./sprites/5.png"));

  grid = loadImage("./sprites/grid.png");
  
}

Map::~Map()
{

 SDL_FreeSurface(grid);

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

  tileRect.x = 0;
  tileRect.y = 0;

  SDL_BlitSurface(grid, NULL, screen, &tileRect);
  
}

int Map::getXY(int x, int y)
{
  return mapVector[y][x];
}

SDL_Surface* Map::loadImage(string filename)
{
    SDL_Surface* temp = NULL;
    SDL_Surface* optimizedImage = NULL;

    temp = IMG_Load(filename.c_str());
    optimizedImage = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 255, 0, 255);
    SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY|SDL_RLEACCEL, colorkey);
    
    return optimizedImage;
}

void Map::setXY(int x, int y, int value)
{
  mapVector[y][x] = value;

  if (value == 5)
    {
      startPosData += "\n" + to_string(x+1) + " " + to_string(y+1);
    }
}

void Map::save(string filename)
{
  ofstream outfile(filename);

  for (unsigned y = 0; y < mapVector.size(); ++y)
    { 
      
      for (unsigned x = 0; x < mapVector[y].size(); x++)
	{
	  if (mapVector[y][x] != 5)
	    outfile << mapVector[y][x] << " ";
	  else
	     outfile << "0 ";
	  
	}

      if (y != mapVector.size()-1)
	outfile << endl;

    }

  outfile << startPosData;

  outfile.close();
  
}

void Map::drawTile(int x, int y, int tile)
{

  SDL_Surface* screen = SDL_GetVideoSurface();

  tileRect.x = x;
  tileRect.y = y;
  SDL_BlitSurface(tiles[tile], NULL, screen, &tileRect);
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
