
#include "map.h"
#include "SDL.h"

#include <iostream>

using namespace std;

int main()
{
  SDL_Surface *screen;

  string filename;
  cout << "Open map: ";
  cin >> filename;

  if (SDL_Init(SDL_INIT_VIDEO /*|SDL_INIT_AUDIO*/) == -1) 
    {
      cout << "Error initializing SDL" << endl;
    }
  
  screen = SDL_SetVideoMode(1024,640, 32, SDL_SWSURFACE|SDL_DOUBLEBUF);
  
  if (screen == NULL) 
    {
      cout << "Error " << endl;
    }

  Map map(filename);

  bool quit = false;
  int x,y;
  int tile = 0;

  while(!quit)
    {


      map.draw();

      SDL_Event ev;

      int mousetileX, mousetileY;
      
      while (SDL_PollEvent(&ev)) 
	{
	  if (ev.type == SDL_KEYDOWN) 
	    {
	      if (ev.key.keysym.sym == SDLK_ESCAPE) 
		{
		  quit = true;		
		} 
	      if (ev.key.keysym.sym == SDLK_0) 
		tile = 0;
	      if (ev.key.keysym.sym == SDLK_1) 
		tile = 1;
	      if (ev.key.keysym.sym == SDLK_2) 
		tile = 2;	      
	      if (ev.key.keysym.sym == SDLK_3) 
		tile = 3;
	      if (ev.key.keysym.sym == SDLK_4) 
		tile = 4;
	      if (ev.key.keysym.sym == SDLK_5) 
		tile = 5;
	      if (ev.key.keysym.sym == SDLK_s) 
		map.save(filename);

	    } 

	  else if (ev.type == SDL_MOUSEMOTION) 
	    {
	      x = ev.motion.x;
	      y = ev.motion.y;
	    } 
	  else if (ev.type == SDL_MOUSEBUTTONDOWN)
	    {

	      if (tile != 0)
		{
		  map.setXY(x/32,y/32,tile);	      
		}
	      else
		{
		  mousetileX = x/32;
		  mousetileY = y/32;
		  //Prevent user from removing "edge-tiles"
		  if (mousetileX != 0 && mousetileX != 31 && mousetileY != 0 && mousetileY != 19)
		    {
		      map.setXY(x/32,y/32,tile);	
		    }
		}	      
	    }
	}  

      //Draw tile under mouse
      map.drawTile(x-16,y-16,tile);
	  

      
      SDL_Flip(screen);  
      SDL_Delay(100);
    }

  SDL_Quit();
  
  cout << "Save to: ";
  cin >> filename;
  map.save(filename);
  
 
  
  return 0;
}
