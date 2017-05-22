

#include "asteroid.hpp"
#include <unistd.h>

#define DELAY 200000 // DELAY directly correlates with any movement of objects in the window the bigger the DELAY the slower an object moves.

Asteroid::Asteroid(){

  y = 0;
  max_y = 0;
  max_x = 0;
  next_y = 0;
  next_x = 0;
  direction_y = 1;
  direction_x = 1;
  waveCount = 1;
}

void Asteroid::setX(){
std::uniform_int_distribution<int> distribution(1,max_x);
}

void Asteroid::setY(){
  next_y = y + direction_y;
  y+= direction_y;
}

int Asteroid::getY(){
  return y;
}
int Asteroid::getX(){
  return x;
}

void Asteroid::printAsteroid(){

     getmaxyx(stdscr, max_y, max_x);

     getX();

    if (next_y != max_y) {
         mvprintw(y, x, " /\\ ");
         mvprintw(y+1, x, " \\/ ");
         //refresh();
         getY();

    }
      else
      {
        y = 1;
        next_y = 0;
        x = distribution(generator);  // generates number in the range 1..6

      }
}
