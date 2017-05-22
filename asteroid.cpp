

#include "asteroid.hpp"
#include <unistd.h>

#define DELAY 200000 // DELAY directly correlates with any movement of objects in the window the bigger the DELAY the slower an object moves.

Asteroid::Asteroid(){
  // getmaxyx(stdscr, max_y, max_x);
  // getX();
  // getY();
  // printAsteroid();
  // getY();

}
void Asteroid::go(){
  etmaxyx(stdscr, max_y, max_x);
  getX();
  getY();
  printAsteroid();
  //getY();

}

void Asteroid::setX(){
std::uniform_int_distribution<int> distribution(1,max_x);
x = distribution(generator);  // generates number in the range 1..6
}

void Asteroid::setY(){
  next_y = 0;
  direction_y = 1;

  if (next_y != max_y) {
  next_y = y + direction_y;
  y+= direction_y;
}

else
{
  y = 1;
  next_y = 0;
  getX();
}
}

int Asteroid::getY(){
  setY();
  return y;
}
int Asteroid::getX(){
  setX();
  return x;
}

void Asteroid::printAsteroid(){

         mvprintw(y, x, " /\\ ");
         mvprintw(y+1, x, " \\/ ");
         //refresh();

}
