//
//  Mark.cpp
//  ncursesPractice
//
//  Created by Joann Ortiz on 5/13/17.
//  Copyright © 2017 Joann Ortiz. All rights reserved.
//

#include "Mark.hpp"

Mark::Mark(WINDOW * win, int y, int x, char m)
{
    markwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(markwin,yMax, xMax);
    //keypad(markwin, true);
    mark = m;
}

void Mark::mvMdown()
{
    int choice = wgetch(markwin);
 
        while(choice == KEY_UP)
        {
          //yLoc++; //adding, moves downs

         mvwaddch(markwin, yLoc, xLoc, ' '); //blank first clears previous -
         mvwaddch(markwin, yLoc, xLoc, '-');
        
            yLoc++; //adding, moves downs
    
            //mvwaddch(markwin, yLoc, xLoc, ' ');
            if (choice != KEY_UP)
            {
                yLoc = yMax;
            }
        }
        /*else{
        yLoc = yMax;
        }*/
    

    //if(yLoc > yMax-2)
    //{// bc bottom border is ymax-1, ymax-2 is right above bottom border
        //yLoc = yMax-2; //if char meets bottom border, stay
       
    //}

    
}

void Mark::display()
{
    mvwaddch(markwin, yLoc, xLoc, mark);

    
}
