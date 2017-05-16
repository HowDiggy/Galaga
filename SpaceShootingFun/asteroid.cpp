#include "asteroid.hpp"
#include <unistd.h>

#define DELAY 200000 // DELAY directly correlates with any movement of objects in the window the bigger the DELAY the slower an object moves.

Asteroid::Asteroid(){

  unsigned int x=1;
  int y=0;
  int xMax= 50; // will change this value to an variable
  int xMin0 = 0;
  int yMax = 100;
}

void Asteroid::setX(){

  int x1 = 1 + (rand() % 50); // will change this value to an variable
  x = x1;
}


void Asteroid::setY(){
  y++;
}

void Asteroid::modY(int i){
  y = i;
}
int Asteroid::getY(){
  return y;
}
int Asteroid::getX(){
  return x;
}

void Asteroid::printAsteroid(){

    // previously-printed characters
    mvprintw(y, x + 1 , "o"); // Print our "ball" at the current xy position
    refresh();
    mvprintw(y + 1, x, "ooo");
    refresh();
    mvprintw(y + 2, x + 1, "o");
    refresh();
    //usleep(DELAY); // Shorter delay between movements
    setY();
}

// void Asteroid::moveAsteroid(){
//
//
//
// }
