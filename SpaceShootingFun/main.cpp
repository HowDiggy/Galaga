//*********************************************************************************************
//  main.cpp
//  ncursesPractice
//*********************************************************************************************

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <random>
#include <vector>
#include "Ship.hpp"
#include "asteroid.hpp"

#define DELAY 200000 // DELAY directly correlates with any movement of objects in the window the bigger the DELAY the slower an object moves.

using namespace std;

int main(int argc, char ** argv)
{

    Asteroid a;
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

    nodelay (win, TRUE);

    //--------------------------------Asteroid-------------------------------

    //a.printAsteroid();
    //--------------------------------------------------------------------------

    //pointer to Player
    Ship * p = new Ship(win, 25, 25, '^', '(', ')', '0', '[', ']', '[', ']');

    // //Asteroid * a = new Asteroid(win, y, x);
    // vector <Asteroid> *a = new vector <Asteroid>(win, y, x);
    //
    //  //vector <Asteroid> a[3]; //vector of Asteroids
    // //a->resize(3);


    while(p->getmv() != 'x')
    {
        clear();
        usleep(DELAY);
        p->display();
        a.printAsteroid();

        refresh();

    }

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
