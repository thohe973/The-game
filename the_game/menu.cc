#include "menu.h"
#include "SDL.h"
#include "game.h"
#include "text.h"
#include "arrow.h"

#include <iostream>

using namespace std;

Menu::Menu()
{
  
  if (SDL_Init(SDL_INIT_VIDEO) == -1) 
    {
      cout << "Error initializing SDL" << endl;
    }
  
  screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, 32, SDL_SWSURFACE|SDL_DOUBLEBUF);
  
  if (screen == NULL) 
    {
      cout << "Error " << endl;
    }
  
  SDL_WM_SetCaption( "THE GAME", NULL );  
  
}

Menu::~Menu()
{
  SDL_FreeSurface(screen);
  SDL_Quit();
}


void Menu::run()
{

  Arrow arrow;

  while (!quit)
    {
      //X on window
      SDL_Event event;
      while(SDL_PollEvent(&event))
      	{
      	  if( event.type == SDL_QUIT )
      	    {
      	      quit = true;
      	    }
      	}

      Uint8 *keys = SDL_GetKeyState(NULL);
      SDL_PumpEvents();  

      if (keys[SDLK_DOWN])  
      	{
      	  arrow.move(320);
      	  current = 2;
      	}
      if (keys[SDLK_UP])
      	{ 
      	  arrow.move(245);
      	  current = 1;
      	}
      if (keys[SDLK_RETURN])
      	{
      	  switch(current)
      	    {
      	    case 1:
      	      {		
      		Game* game = new Game;
      		if (game->run() == 1)
      		  {
      		    quit = true;
      		  }
      		delete game;
      		break;
      	      }
      	    case 2:
      	      {
      		quit = true;
      		break;
      	      }
      	    default:
      	      {
      		break;
      	      }
      	    }
      	}

      myText.drawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
      myText.drawText(360, 225, "Start Game");
      myText.drawText(360, 305, "Exit Game");      
      arrow.draw();

      
      SDL_Flip(screen);
      SDL_Delay(10);    

    }
}
