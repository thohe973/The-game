#include "game.h"
#include <iostream>
#include <fstream>
#include "player.h"
#include "map.h"
#include "cloud.h"
#include "timer.h"
#include "text.h"
#include "powerup.h"

using namespace std;

Game::Game()
{

  ifstream levfile("./maps/levels.lev");
  string levelname;

  while(getline(levfile,levelname,'\n'))
    {
      levels.push_back(levelname);
    }

  levfile.close();

}

Game::~Game() 
{ 
  deleteLevel();
}

int Game::run()
{
  int frame = 0;
  bool cap = true; 

  for (unsigned i = 0; i < levels.size(); ++i)
    {
      if (quit == true)
	{
	  break;
	}
      loadLevel(levels[i]);	
    
      levelComplete = false;
      showPowerup = true;
      quit = false;
      freeze = false; 

      while(!quit && !levelComplete)
	{

	  //X on window
	  SDL_Event event;
	  while(SDL_PollEvent(&event))
	    {
	      if( event.type == SDL_QUIT )
		{
		  return 1;
		}
	    }

	  //Start the frame timer
	  fps.start();
	  
	  Uint8 *keys = SDL_GetKeyState(NULL);
	  SDL_PumpEvents();  
	  
	  if (keys[SDLK_r])
	    {
	      for (Player* player: players)
		{
		  player->reset();
		}
	      showPowerup = true;
	      freeze = false; 
	    }   
	  
	  if(keys[SDLK_ESCAPE]) quit = true;
	  
	  //Players can only move if they arent dead or they won
	  if (!freeze)
	    {

	      if (keys[SDLK_n])     
		{
		  levelComplete = true;
		  SDL_Delay(100);
		}

	      if (keys[SDLK_LEFT])  players[0]->move(-4);
	      if (keys[SDLK_RIGHT]) players[0]->move(4);
	      if (keys[SDLK_UP])    players[0]->jump();
	      
	      if (keys[SDLK_a])     players[1]->move(-4);
	      if (keys[SDLK_d])     players[1]->move(4);
	      if (keys[SDLK_w])     players[1]->jump();   
	      
	      map->draw();

	      if (showPowerup)
		{
		  powerup->draw();
		  powerup->move(8);
		}

	      if (players[0]->getYellow() || players[1]->getYellow())
		{
		  strike = true;
		}
	      else
		{
		  strike = false;
		}	      
	      
	      for (Cloud*& cloud : clouds)
		{
		  cloud->draw();
		  cloud->move(strike);
		}
	      
	      for (Player*& player : players)
		{
		  if (showPowerup)
		    {
		      if (checkColl(player->getRect(), powerup->getRect()))
			{
			  player->setJumpSpeed(-30);
			  showPowerup = false;
			}
		    }

		  for (Cloud*& cloud : clouds)
		    {
		      if (cloud->getRect().h != 32)
			{
			  if (checkColl(player->getRect(),cloud->getRect()))
			    {
			      freeze = true;
			    }
			}
		    }
		  player->draw();
		  player->gravity();
		}     

	      if (freeze)
		{
		  myText.drawBox(362, 220, 300, 200);
		  myText.drawText(380, 250, "r to restart");
		  myText.drawText(380, 320, "esc to exit");
		}

	      if (players[0]->getGreen() && players[1]->getGreen())
		{
		  freeze = true;
		  
		  if (i != levels.size()-1)
		    {
		      levelComplete = true;
		    }
		  else
		    {       
		      myText.drawBox(362, 220, 300, 200);
		      myText.drawText(400, 250, "The end");
		      myText.drawText(380, 320, "esc to exit");
		    }		
		}
	    }//End of freeze
    
	  SDL_Flip(SDL_GetVideoSurface());      

	  frame++;
	  if( (cap == true) && (fps.get_ticks() < 1000 / FRAMES_PER_SECOND) )
	    {
	      SDL_Delay( (1000 / FRAMES_PER_SECOND) - fps.get_ticks() );
	    }
      
	} //End game-loop
    } //End of for-loop

  return 0;
}

//Creates all the objects in the given file.
void Game::loadLevel(string filename)
{
  deleteLevel();

  map = new Map(filename);

  ifstream infile(filename);
  string trash;

  //Skip leveldata
  for (int i = 0; i < SCREEN_HEIGHT/32; ++i)
    {
      getline(infile,trash,'\n');
    }

  int powerX, powerY;

  infile >> powerX >> powerY;
  powerup = new Powerup(powerX, powerY);

  string playerOnePNG, playerTwoPNG;
  int p1X, p1Y, p2X, p2Y;
  
  infile >> playerOnePNG >> p1X >> p1Y >> playerTwoPNG >> p2X >> p2Y;
 
  players.push_back(new Player(playerOnePNG,p1X,p1Y));
  players.push_back(new Player(playerTwoPNG,p2X,p2Y));
    
  players[0]->setMap(map);
  players[1]->setMap(map);   

  int cloudX, cloudY, cloudMovement, cloudDir, cloudThunder;

  while(infile >> cloudX >> cloudY >> cloudMovement >> cloudDir >> cloudThunder)
    {      
      clouds.push_back(new Cloud(cloudX,cloudY, cloudMovement, cloudDir, cloudThunder));
    }
  
}

bool Game::checkColl(SDL_Rect& a, SDL_Rect& b) const
{    

  if ((a.x + a.w > b.x && b.x >= a.x) || (b.x + b.w > a.x && a.x > b.x))
    {
      if ((a.y + a.h > b.y && b.y > a.y) || (b.y + b.h > a.y && a.y > b.y)) 
	{
	  return true;
	}
    }

  return false;
    
}

void Game::deleteLevel()
{
  //Delete all objects
  for (Cloud* cloud : clouds)
    { 
      delete cloud; 
    }
  
  for (Player* player : players) 
    { 
      delete player; 
    }
  
  if (map != nullptr)
    {
      delete map;
    }

  if (powerup != nullptr)
    {    
      delete powerup;
    }

  players.clear();
  clouds.clear();
}
