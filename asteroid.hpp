

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;

 class Asteroid{
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
   static std::default_random_engine generator;

    WINDOW * curwin; //window

    static int getRandom(){


      return (2 + (2 * rand ()) %100);
      // std::uniform_int_distribution<int> distribution(1,100);
      // return distribution(generator);  // generates number in the range 1..6
    }

 public:
     //Asteroid(WINDOW * win, int y, int x); //constructor w/ window


     Asteroid();
     void go();
     void setY();
     void setX();
     int getY();
     int getX();
     void printAsteroid(){


       mvprintw(y, this-> x, "@@");
       mvprintw(y+1, this-> x, "@@");
       //refresh();

     }

     void randomX(int x){
       this-> x = x;
     }
};

#endif /* Asteroid_hpp */
