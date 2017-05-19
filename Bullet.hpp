//
//  Bullet.hpp
//  Project
//
//  Created by Alexis Paredes on 5/18/17.
//  Copyright © 2017 Alexis Paredes. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <ncurses.h>
#include <cstdlib>
#include <random>
#include <iostream>


class Bullet
{
private:
    bool isMoving;
    int y;
    int x;
    int max_y;
    int max_x;
    int next_y;
    int next_x;
    int direction_y;
    int direction_x;
    WINDOW * curwin; //window
public:
    Bullet();
    void setY();
    void setX();
    int getY();
    int getX();
    void printBullet(int x, int y);
    
    
    
};

#endif /* Bullet_hpp */
