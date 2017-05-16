//*********************************************************************************************
//  main.cpp
//  ncursesPractice
//*********************************************************************************************

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include "Ship.hpp"

using namespace std;

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
    
    wrefresh(win2);
    
    //pointer to Player
    Ship * p = new Ship(win, 41, 39, '^', '(', ')', '0', '[', ']', '[', ']');
    
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
