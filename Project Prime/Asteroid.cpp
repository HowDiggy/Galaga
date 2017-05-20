#include "Asteroid.hpp"
#include <unistd.h>
#include <random>
#include <iostream>

#define DELAY 200000 // DELAY directly correlates with any movement of objects in the window the bigger the DELAY the slower an object moves.

Asteroid::Asteroid(WINDOW * win, int y, int x)
{
    curwin = win; //win refers to main window in main()
    y = 0;
    x = 1;
}

Asteroid::Asteroid()
{
    y = 0;
    max_y = 0;
    max_x = 0;
    next_y = 0;
    next_x = 0;
    direction_y = 1;
    direction_x = 1;
    waveCount = 1;
}

void Asteroid::setX()
{
    
}

void Asteroid::setY()
{
 
}

void Asteroid::modY(int i)
{
    
}

int Asteroid::getY()
{
    return y;
}

int Asteroid::getX()
{
    return x;
}

//void Asteroid::printAsteroid()
void Asteroid::printAsteroid(WINDOW *win)
{
    // Global var `stdscr` is created by the call to `initscr()`
    //getmaxyx(stdscr, max_y, max_x);
    
    
    std::default_random_engine generator;
    
    //  for(int i=0; i < waveCount; i++){
    
    // getmaxyx(stdscr, max_y, max_x);
     getmaxyx(win, max_y, max_x);
    
    max_y = 42; //"o*" stops at border, leaves mark
    //max_x = 2;

    
    std::uniform_int_distribution<int> distribution(1,max_x);
    x = distribution(generator);  // generates number in the range 1..6
    
    // next_x = x + direction_x;
    // x+= direction_x;
    
    //srand(time(NULL));
    //int r = rand() % 50;
    
    if (next_y != max_y)
    {
        //clear();
        
        mvwprintw(win, y+1, x, "o"); //originally y

        mvwprintw(win, y+2, x, "*"); //originally y+1
        
        mvwprintw(win, y, x, " ");  //w/ -prints "o*" no trail


        //mvprintw( y, x, " /\\ ");
        //mvprintw( y+1, x, " \\/ ");
        //mvprintw(y+2, x, " o ");

        
        //usleep(DELAY);
        
        next_y = y + direction_y;
        y+= direction_y;
        
            if (next_y == max_y) //erases "o*" string just before it touches the border
            {
                mvwprintw(win, y, x, " ");
                mvwprintw(win, y+1, x, " ");
            }
    }
    
    
    else //ensures continuity of asteroids falling
    {
        y = 1;
        
        next_y = 0;
        
    }
    
        
        
    
    
    
    // x = 1;
    // next_x = 0;
    //  }
}




