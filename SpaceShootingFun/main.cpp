//*********************************************************************************************
//  main.cpp
//  ncursesPractice
//*********************************************************************************************

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
<<<<<<< Updated upstream
#include <vector>
=======
>>>>>>> Stashed changes
#include "Ship.hpp"
#include "Asteroid.hpp"


using namespace std;

<<<<<<< Updated upstream
int main(int argc, char ** argv)
{
    /*NCurses START*/
    initscr(); //initialize screen-always include/sets up memory and clears screen
    cbreak(); //Control+C exits program
    noecho(); //user input doesn't show on screen
    
    //get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    
    //set size of window-position on terminal screen
    int height, width, start_y, start_x;
    height = 45;
    width = 80;
    start_y = 0;
    start_x = 0; //added value moves window right
    
    //customize window appearance-using pointer
    WINDOW * win = newwin(height, width, start_y, start_x);
    refresh();
    
    char plus = '+';
    char dash = '-';
    char line = '|';
    
    int left, right, top, bottom, tlc, trc, blc, brc;
    
    left = line;
    right = line;
    top = dash;
    bottom = dash;
    blc = plus;
    brc = plus;
    tlc = plus;
    trc = plus;
    
    wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
    //wborder(win, left, right, top, bottom, tlc, trc, blc, brc); accepts int values or characters
    
    WINDOW * win2 = newwin(4, 80, 45, 0); //height, width, start_y, start_x)
    
    wborder(win2, left, right, top, bottom, tlc, trc, blc, brc);
    
    mvwprintw(win2, 1, 1, "Count: %i"); //wave-checkpoint mark
    
    mvwprintw(win2, 2, 1, "Use UP, DOWN, LEFT, RIGHT arrow keys. CTRL+C to escape.");
    
    wrefresh(win2);
    
    //--------------------------------Asteroid-------------------------------
    
    srand(time(NULL));
    
    //collision
    //int direction = 1;
    //int next_x = 0;
    
    int x = 0, y = 0;
    int numberOfAsteroids = 3;
    
    vector <Asteroid> v; //vector of Asteroids
    
    v.resize(numberOfAsteroids);
    
    while(1)
    {
        getmaxyx(stdscr, yMax, xMax);
        clear();
        
        for(int i = 0; i < numberOfAsteroids; i++)
        {
            v[i].setX();
            v[i].modY(1);
            v[i].printAsteroid();
        }
    
    //refresh();
    
        for(int j = 0; j < 40; j++)
        {
            for(int i = 0; i < numberOfAsteroids; i++)
            {
                v[i].modY(v[i].getY() + 1);
            }
        
            clear();
            
        
            for(int i = 0; i < numberOfAsteroids; i++)
            {
                v[i].printAsteroid();
            
                /*
                 next_x = y + direction; //not x
            
                 if (next_x >= v[i].yMax || next_x < 0)
                 {
                    direction*= -1;
                 }
                 else
                 {
                    y+= direction; //not x
                 }*/
            }
     
        usleep(150000); //200000
     
        //refresh();
        }
    }
    
    //--------------------------------------------------------------------------

    //pointer to Player
    Ship * p = new Ship(win, 41, 39, '^', '(', ')', '0', '[', ']', '[', ']');
    
    //Asteroid * a = new Asteroid(win, y, x);
    vector <Asteroid> *a = new vector <Asteroid>(win, y, x);
    
     //vector <Asteroid> a[3]; //vector of Asteroids
    //a->resize(3);
   
    
    while(p->getmv() != 'x')
    {
        p->display();
        refresh();
        

=======
 int main(int argc, char ** argv)
 {
     /*NCurses START*/
     initscr(); //initialize screen-always include/sets up memory and clears screen
     cbreak(); //Control+C exits program
     noecho(); //user input doesn't show on screen

     //get screen size
     int yMax, xMax;
     getmaxyx(stdscr, yMax, xMax);

     //set size of window-position on terminal screen
     int height, width, start_y, start_x;
     height = 45;
     width = 80;
     start_y = 0;
     start_x = 0; //added value moves window right

     //customize window appearance-using pointer
     WINDOW * win = newwin(height, width, start_y, start_x);
     refresh();

     char plus = '+';
     char dash = '-';
     char line = '|';

     int left, right, top, bottom, tlc, trc, blc, brc;

     left = line;
     right = line;
     top = dash;
     bottom = dash;
     blc = plus;
     brc = plus;
     tlc = plus;
     trc = plus;

     wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
     //wborder(win, left, right, top, bottom, tlc, trc, blc, brc); accepts int values or characters

     WINDOW * win2 = newwin(4, 80, 45, 0);

     wborder(win2, left, right, top, bottom, tlc, trc, blc, brc);

     mvwprintw(win2, 1, 1, "Count: %i"); //wave-checkpoint mark

     mvwprintw(win2, 2, 1, "Use UP, DOWN, LEFT, RIGHT arrow keys. CTRL+C to escape.");
>>>>>>> Stashed changes

    }


<<<<<<< Updated upstream

    /*
    score = 0;
    while (1) {
        usleep(200000);
        score++;
        mvwprintw(score_win, 0, 0, "Score: %d", score);
        wrefresh(score_win);
    }*/
    
    //make sure program waits before exiting
    getch();
    
    //deallocates memory and ends ncurses
    endwin();
    
    /*NCurses END*/
    return 0;
}
=======
     //pointer to Player
     Player * p = new Player(win, 43, 39, '@'); //pointer to Player class, with win parameters

     while(p->getmv() != 'x')
     {
         p->display();

         refresh();
     }

     //make sure program waits before exiting
     getch();

     //deallocates memory and ends ncurses
     endwin();

     /*NCurses END*/
 return 0;
 }
>>>>>>> Stashed changes
