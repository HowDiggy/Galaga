//
//  Bullet.cpp
//  Project
//
//  Created by Alexis Paredes on 5/18/17.
//  Copyright © 2017 Alexis Paredes. All rights reserved.
//

#include "Bullet.hpp"
#include <unistd.h>
#define DELAY 200000


Bullet::Bullet(){
    y = 0;
    max_y = 0;
    max_x = 0;
    next_y = 0;
    next_x = 0;
    direction_y = 1;
    direction_x = 1;
}
int Bullet::getY()
{
    return y;
}
int Bullet::getX()
{
    return x;
}
void Bullet::printBullet(int x, int y)
{
    getmaxyx(stdscr, max_y, max_x);
    this -> x = x;
    this -> y = y;
    char choice = wgetch(curwin);
    if (choice == 'k'){
        while(next_y != max_y) {
            clear();
            mvprintw(y, x, "$");
        
        
            refresh();
        
            usleep(DELAY);
        
            next_y = y - direction_y;
            y+= direction_y;

        }
    }
}
