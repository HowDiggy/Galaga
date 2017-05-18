//
//  Ship.cpp
//  Project
//
//  Created by Alexis Paredes on 5/9/17.
//  Copyright © 2017 Alexis Paredes. All rights reserved.
//

#include "Ship.hpp"

//Player(Window, start value of y, x and character display)
Ship::Ship (WINDOW * win, int y, int x, char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8) //constructor
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin,yMax, xMax);
    keypad(curwin, true);
    ch1 = c1;
    ch2 = c2;
    ch3 = c3;
    ch4 = c4;
    ch5 = c5;
    ch6 = c6;
    ch7 = c7;
    ch8 = c8;
    display();
}

//movements
void Ship::mvup()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    mvwaddch(curwin, yLoc+1, xLoc-1, ' ');
    mvwaddch(curwin, yLoc+1, xLoc, ' ');
    mvwaddch(curwin, yLoc+1, xLoc+1, ' ');
    mvwaddch(curwin, yLoc+2, xLoc-2, ' ');
    mvwaddch(curwin, yLoc+2, xLoc-1, ' ');
    mvwaddch(curwin, yLoc+2, xLoc+2, ' ');
    mvwaddch(curwin, yLoc+2, xLoc+1, ' ');

    yLoc--;
    if(yLoc < 1) //if it goes out of bounds
        yLoc = 1;
}

void Ship::mvdown()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    mvwaddch(curwin, yLoc+1, xLoc-1, ' ');
    mvwaddch(curwin, yLoc+1, xLoc, ' ');
    mvwaddch(curwin, yLoc+1, xLoc+1, ' ');
    mvwaddch(curwin, yLoc+2, xLoc-2, ' ');
    mvwaddch(curwin, yLoc+2, xLoc-1, ' ');
    mvwaddch(curwin, yLoc+2, xLoc+2, ' ');
    mvwaddch(curwin, yLoc+2, xLoc+1, ' ');
    yLoc++; //adding, moves down
    if(yLoc > yMax-2) // bc bottom border is ymax-1, ymax-2 is right above bottom border
        yLoc = yMax-2;
}

void Ship::mvleft()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    mvwaddch(curwin, yLoc+1, xLoc-1, ' ');
    mvwaddch(curwin, yLoc+1, xLoc+1, ' ');
    mvwaddch(curwin, yLoc+2, xLoc-2, ' ');
    mvwaddch(curwin, yLoc+2, xLoc-1, ' ');
    mvwaddch(curwin, yLoc+2, xLoc+2, ' ');
    mvwaddch(curwin, yLoc+2, xLoc+1, ' ');
    xLoc--;
    if(xLoc < 3)
        xLoc = 3;
}

void Ship::mvright()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    mvwaddch(curwin, yLoc+1, xLoc-1, ' ');
    mvwaddch(curwin, yLoc+1, xLoc+1, ' ');
    mvwaddch(curwin, yLoc+2, xLoc-2, ' ');
    mvwaddch(curwin, yLoc+2, xLoc-1, ' ');
    mvwaddch(curwin, yLoc+2, xLoc+2, ' ');
    mvwaddch(curwin, yLoc+2, xLoc+1, ' ');
    xLoc++;
    if(xLoc > xMax-4)
        xLoc = xMax-4;
}

int Ship::getmv() //return int value of key pressed
{
    int choice = wgetch(curwin);
    switch(choice)
    {
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
    }

    return choice;
}

void Ship::display() //display position character is at
{
    //mvwaddch-lets you use single character
    mvwaddch(curwin, yLoc, xLoc, ch1);
    mvwaddch(curwin, yLoc+1, xLoc-1, ch2);
    mvwaddch(curwin, yLoc+1, xLoc, ch4);
    mvwaddch(curwin, yLoc+1, xLoc+1, ch3);
    mvwaddch(curwin, yLoc+2, xLoc-2, ch5);
    mvwaddch(curwin, yLoc+2, xLoc-1, ch6);
    mvwaddch(curwin, yLoc+2, xLoc+2, ch8);
    mvwaddch(curwin, yLoc+2, xLoc+1, ch7);
    curs_set(0);

}
