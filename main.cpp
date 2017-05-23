//***************************************************************************************************
// main.cpp
//
// Summary: This program utilizes the ncurses library to create a text-based game. It incorporates two
//          other classes, Ship and asteroid, to print a ship and asteroid objects onto a window. It
//          takes user input in the form of arrow keys to move the ship in four directions.
//
// Authors: Joann, Paulo, Osiel, Alexis
// Created: May 2017
//
//***************************************************************************************************

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

    //Asteroid  b, c;
    std::vector<Asteroid> asteroids;
    asteroids.resize(10);
    for(int x= 0; x < 10; x++){
      Asteroid a , b;
      b.randomX(x * 10);
      asteroids[x] = b;

    }
    /*NCurses START*/
    initscr(); //initialize screen-always include/sets up memory and clears screen
    cbreak(); //Control+C exits program
    noecho(); //user input doesn't show on screen

    //get screen size
    int yMax, xMax;
    int max_x;
    int max_y;
    getmaxyx(stdscr, yMax, xMax);
    getmaxyx(stdscr, max_y, max_x);

    //set size of window-position on terminal screen
    int height, width, start_y, start_x;
    height = max_y;
    width = max_x;
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

    //pointer to Player
    Ship * p = new Ship(win, 25, 25, '^', '(', ')', '0', '[', ']', '[', ']');

    // //Asteroid * a = new Asteroid(win, y, x);
    // vector <Asteroid> *a = new vector <Asteroid>(win, y, x);
    //
    //  //vector <Asteroid> a[3]; //vector of Asteroids
    // //a->resize(3);
    //std::default_random_engine generator;
    // std::uniform_int_distribution<int> distribution(1,80);
    // int x = distribution(generator);  // generates number in the range 1..6

    srand(time(NULL));

    while(p->getmv() != 'x')
    {
        //clear();
        usleep(DELAY);
        p->display();


        for(int h = 0; h < 10; h++){
          asteroids[h].go();
          DELAY;

        }


        refresh();
        clear();

    }

    //make sure program waits before exiting
    getch();

    //deallocates memory and ends ncurses
    endwin();

    /*NCurses END*/
    return 0;
}
