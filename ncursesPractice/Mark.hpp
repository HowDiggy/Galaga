//
//  Mark.hpp
//  ncursesPractice
//
//  Created by Joann Ortiz on 5/13/17.
//  Copyright © 2017 Joann Ortiz. All rights reserved.
//

#ifndef Mark_hpp
#define Mark_hpp

#include <iostream>
#include <ncurses.h>

using namespace std;

class Mark
{
public:
    Mark(WINDOW * win, int y, int x, char m);
    
    void mvMdown();
    
    void display();
    
private:
    int xLoc;
    int yLoc;
    int xMax;
    int yMax;
    char mark;
    WINDOW * markwin;
      
    
};

#endif /* Mark_hpp */
