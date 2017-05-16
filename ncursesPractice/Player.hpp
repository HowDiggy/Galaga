//
//  Player.hpp
//  ncursesPractice
//
//  Created by Joann Ortiz on 5/6/17.
//  Copyright © 2017 Joann Ortiz. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <ncurses.h>
using namespace std;

class Player
{
public:
    //Player(Window, start value of y, x and character display)
    Player(WINDOW * win, int y, int x, char c); //constructor
    
    //movements
    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    
    int getmv(); //return int value of key pressed
    
    void display(); //display position character is at
    
private:
    int xLoc, yLoc, xMax, yMax;
    char character;
    WINDOW * curwin;
    
};

#endif /* Player_hpp */
