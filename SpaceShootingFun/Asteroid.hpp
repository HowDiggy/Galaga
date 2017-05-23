

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include <iostream>

 #include <ncurses.h>
 #include <vector>
 #include <cstdlib>

 class Asteroid
{
 private:
     int x, y, xMax, xMin, yMax;
     char character;
     
 public:
     Asteroid();
     void setY();
     void setX();
     int getY();
     int getX();
     void modY(int i);
    
    
     void printAsteroid();
};

#endif /* Asteroid_hpp */
