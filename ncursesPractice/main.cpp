//*********************************************************************************************
//  main.cpp
//  ncursesPractice
//
//  Ncurses tutorial 3-Borders and other functions
//                      -made a window, adjusted height,width,start_x and start_y
//  Ncurses tutorial 4- Attributes and Colors
//   https://www.youtube.com/watch?v=DtMfkShh03w
//  Ncurses tutorial 6 - User Input-key functions
//   https://www.youtube.com/watch?v=vfNI0n5vFLE
//*********************************************************************************************

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include "Player.hpp"
#include "Mark.hpp"


using namespace std;

//int argc, char ** argv
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
     start_y = 0; //10
     start_x = 0; //added value moves window right
     
     //customize window appearance-using pointer
     WINDOW * win = newwin(height, width, start_y, start_x);
     refresh();
     //WINDOW * win2 = newwin(10, 5, 10, 10);
     
     //wrefresh(win2);
     //refresh();
     
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
     
     //make border with declared characters
     //while cursor moves...or for every # of rows

     wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
     //reference: wborder(win, left, right, top, bottom, tlc, trc, blc, brc); accepts int values or characters
     
     WINDOW * win2 = newwin(4, 80, 45, 0);

     wborder(win2, left, right, top, bottom, tlc, trc, blc, brc);
     
     mvwprintw(win2, 1, 1, "Count: %i"); //wave-checkpoint mark
     
     /*
     int seconds = 0;
     do {
         //mvwprintw(win2, 1, 1, "%i");
         mvwprintw(win2, 1, 1, "Seconds: %i");

         wrefresh(win2); //refresh(); refresh standard window
         erase();
         seconds++;
         sleep(1);
     } while (seconds > 0);
     */
     
     mvwprintw(win2, 2, 1, "Use UP, DOWN, LEFT, RIGHT arrow keys. CTRL+C to escape.");

     wrefresh(win2);
     
     /*
     //Timer: counts up seconds from 0
     int seconds = 0;
     
     do {
         printw("Seconds: %i", seconds);
         refresh();
         erase();
         seconds++;
         sleep(1);
     } while (seconds > 0);
     */
   
     //Objects * obj = new Objects(win, 20, 0, '*');
     
     //char asteroids[3][1] = {{'*'},
           //                 {'*'},
                   //         {'*'}};
     
     //pointer to Player
     Player * p = new Player(win, 43, 39, '@'); //pointer to Player class, with win parameters
     Mark * s = new Mark(win, 1, 1, '*');
     
     while(p->getmv() != 'x')
     {
         p->display();
         //wrefresh(win);
         
         
         s->display();
         refresh();
     }
     
     /*
     for (int i = 0; i < 3; i++)
     {
         for(int j = 0; j < 1; j++)
         {
             cout << asteroids[i][j];
         }
         cout << endl;
     }*/
     
     
     //make sure program waits before exiting
     getch();
     
     //deallocates memory and ends ncurses
     endwin();
     
     /*NCurses END*/
 return 0;
 }







/*
 // create a window for our output
 WINDOW * playwin = newwin(20, 50,(yMax/2)-10, 10);
 box(playwin, 0, 0);
 refresh();
 wrefresh(playwin);
 */

/* after initscr,noecho and cbreak functions
 //set size of window
 int height, width, start_y, start_x;
 height = 50;
 width = 80;
 start_y = 0; //10
 start_x = 0;
 
 //customize window appearance-using pointer
 WINDOW * win = newwin(height, width, start_y, start_x);
 refresh();
 
 char plus = '+';
 char dash = '-';
 char line = '|';
 
 //box(win, 103, 104); //left/right, top/bottom - int value of letter
 int left, right, top, bottom, tlc, trc, blc, brc;
 
 left = line;
 right = line;
 top = dash;
 bottom = dash;
 blc = plus;
 brc = plus;
 tlc = plus;
 trc = plus;
 
 //make border with declared characters
 wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
 //reference: wborder(win, left, right, top, bottom, tlc, trc, blc, brc); accepts int values or characters
 
 //print text inside the window
 //mvwprintw(win, 1 , 1, "testing text");
 
 **window for info
 **WINDOW * win2 = newwin(2, 80, 1, 0); //tried adding another window...
 
 wrefresh(win);
 
 keypad(win,true);
 
 int c = wgetch(win);
 if(c == KEY_UP)
 {
 //mvprintw(window, columns, rows, string to print)
 mvwprintw(win, 3, 5, "you pressed UP");
 wrefresh(win);
 }
 
 if(c == KEY_DOWN)
 {
 //mvprintw(window, columns, rows, string to print)
 mvwprintw(win, 3, 5, "you pressed DOWN");
 wrefresh(win);
 }
 
 getch();

 */


/* Other code and functions
 
  //raw(); //takes all input as raw input, doesn't accept special characters

  int x, y;
  x = y = 10;

 //move(y,x): moves the cursor to the specified location
 move(y, x);
 
 //printw: prints a string (const char *) to a window
 printw("Hello world");
 
 
 //getch(): waits for user input to press key, returns int value of that key
 int c = getch();
 
 //clears the screen, after user input of a char(from getch() function)
 clear();
 
 move(0,0);
 printw("%d", c);
 
 //refresh(): refreshes the screen to match whats in memory
 refresh();

 //usleep(2000);
 
*/
