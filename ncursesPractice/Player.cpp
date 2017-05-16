//
//  Player.cpp
//  ncursesPractice
//
//  Source: Ncurses tutorial 8- Basic top down player

#include "Player.hpp"

//Player(Window, start value of y, x and character display)
Player::Player (WINDOW * win, int y, int x, char c) //constructor
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin,yMax, xMax);
    keypad(curwin, true);
    character = c;
}

//movements
void Player::mvup()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc--;
    if(yLoc < 1) //if it goes out of bounds
        yLoc = 1;
}

void Player::mvdown()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++; //adding, moves down
    if(yLoc > yMax-2) // bc bottom border is ymax-1, ymax-2 is right above bottom border
        yLoc = yMax-2;
}

void Player::mvleft()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');

    xLoc--;
    if(xLoc < 3) //changed to 3 for ship
        xLoc = 3;
}

void Player::mvright()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');

    xLoc++;
    if(xLoc > xMax-2)
        xLoc = xMax-2;
}

int Player::getmv() //return int value of key pressed
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

void Player::display() //display position character is at
{
    //mvwaddch-lets you use single character 
    mvwaddch(curwin, yLoc, xLoc, character);
   // mvwaddch(curwin, yLoc+1, xLoc-2, ch2);
    //mvwaddch(curwin, yLoc+1, xLoc+2, ch3);
    
    
    curs_set(0);
    
}


