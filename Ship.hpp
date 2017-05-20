//
//  Ship.hpp
//  Project
//
//  Created by Alexis Paredes on 5/9/17.
//  Copyright © 2017 Alexis Paredes. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <ncurses.h>

class Ship
{
private:
    int xLoc, yLoc, xMax, yMax;
    //char character;
    
    char ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8;
    WINDOW * curwin;
    
    //added
    int y;
    int next_y;
    int direction_y;
    
public:
    //Player(Window, start value of y, x and character display)
    Ship(WINDOW * win, int y, int x, char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8);
    //constructor
    
    //movements
    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int getmv(); //return int value of key pressed
    
    int getyLoc();
    int getxLoc();
    
    void display(); //display position character is at
};

#endif /* Ship_hpp */
