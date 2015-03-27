#ifndef TIMER_H
#define TIMER_H

/**
 * This class is based on the work by Lazy foo - http://lazyfoo.net/SDL_tutorials/lesson14/index.php
 */


class Timer
{
 public:
  //Initializes variables
  Timer();
  
  //The various clock actions
  void start();
  void stop();
  void pause();
  void unpause();
  
  //Gets the timer's time
  int get_ticks();
  
  //Checks the status of the timer
  bool is_started();
  bool is_paused();
  
 private:
  //The clock time when the timer started
  int startTicks;
  
  //The ticks stored when the timer was paused
  int pausedTicks;
  
  //The timer status
  bool paused;
  bool started;
};


#endif
