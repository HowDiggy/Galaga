#include "asteroid.hpp"
#include <unistd.h>

#define DELAY 200000 // DELAY directly correlates with any movement of objects in the window the bigger the DELAY the slower an object moves.

Asteroid::Asteroid(){

  int y = 0;
  int max_y = 0, max_x = 0;
  int next_y = 0, next_x = 0;
  int direction_y = 1;
  int direction_x = 1;
  int waveCount = 1;
}

void Asteroid::setX(){

}


void Asteroid::setY(){
}

void Asteroid::modY(int i){

}
int Asteroid::getY(){
  return y;
}
int Asteroid::getX(){
  return x;
}

void Asteroid::printAsteroid(){

  // Global var `stdscr` is created by the call to `initscr()`
  //getmaxyx(stdscr, max_y, max_x);

  std::default_random_engine generator;


  for(int i=0; i < waveCount; i++){



   while(1) {

     getmaxyx(stdscr, max_y, max_x);

     std::uniform_int_distribution<int> distribution(1,max_x);
     int x = distribution(generator);  // generates number in the range 1..6
   // next_x = x + direction_x;
   // x+= direction_x;

     while(next_y != max_y) {
         clear();
         mvprintw(y, x, " /\\ ");
         mvprintw(y+1, x, " \\/ ");
         //mvprintw(y+2, x, " o ");
         refresh();

         usleep(DELAY);

         next_y = y + direction_y;
         y+= direction_y;


         }

     y = 1;
     next_y = 0;
     }
   // x = 1;
   // next_x = 0;
  }




}

// void Asteroid::moveAsteroid(){
//
//
//
// }
