//*********************************************************************************************
//  main.cpp
//  ncursesPractice
//*********************************************************************************************

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <random>
//#include <vector>
#include "Ship.hpp"
#include "Asteroid.hpp"
//#include "Bullet.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    /*NCurses START*/

    Asteroid a;
    //Bullet b;

    bool hit = false;

    int score = 0;

    initscr(); //initialize screen-always include/sets up memory and clears screen
    cbreak(); //Control+C exits program
    noecho(); //user input doesn't show on screen

    //get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //Start screen
    curs_set(0); //hides cursor

    char text1[] = "*   *  Space Mission  *   *";
    char text2[] = "Made by Osiel, Joann, Paulo, Alexis";
    char text3[] = "Press any key to start";

    mvprintw((yMax / 2) - 2, (xMax - sizeof(text1)) / 2, "%s", text1);
    mvprintw(yMax / 2, (xMax - sizeof(text2)) / 2, "%s", text2);
    mvprintw((yMax / 2) + 4, (xMax - sizeof(text3)) / 2, "%s", text3);

    getch(); //waits for user to enter key


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

    mvwprintw(win2, 2, 1, "Use UP, DOWN, LEFT, RIGHT arrow keys. CTRL+C or X to quit.");

    wrefresh(win2);

    nodelay (win, TRUE);


    //--------------------------------------------------------------------------

    //pointer to Player
    Ship * p = new Ship(win, 41, 39, '^', '(', ')', '0', '[', ']', '[', ']');

    //int y, x;

    while(p->getmv() != 'x')
    {
        //refresh();

        usleep(200000); //DELAY

        refresh();

        p->display();

        a.printAsteroid(win); //added win, made no difference

        //refresh();

        if((p->getyLoc() && p->getxLoc() == a.getY() && a.getX()))
        {
            clear();
            hit = true;
        }



        //b.printBullet(39,41); // (int x, int y)

        //timer in seconds
        usleep(200000);

        score++;

        mvwprintw(win2, 1, 1, "Time: %d seconds", score);

        wrefresh(win2);


        refresh();

    }



    //make sure program waits before exiting
    getch();

    //deallocates memory and ends ncurses
    endwin();

    /*NCurses END*/
    return 0;
}

//Asteroid * a = new Asteroid(win, y, x);
//vector <Asteroid> *v = new vector <Asteroid>;
