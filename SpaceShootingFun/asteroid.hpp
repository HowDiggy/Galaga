

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <cstdlib>

using namespace std;

 class Asteroid
{
 public:
    int x, y;
    int xMax, yMax; 
    int xMin;
    char character;
    
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
