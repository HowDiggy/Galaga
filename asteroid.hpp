

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;

 class Asteroid
{
private:
   int y;
   int x;
   int max_y;
   int max_x;
   int next_y;
   int next_x;
   int direction_y;
   int direction_x;
   int waveCount;
   std::default_random_engine generator;

    WINDOW * curwin; //window

 public:
     Asteroid(WINDOW * win, int y, int x); //constructor w/ window


     Asteroid();
     void setY();
     void setX();
     int getY();
     int getX();
     void modY(int i);

     void printAsteroid();
};

#endif /* Asteroid_hpp */
