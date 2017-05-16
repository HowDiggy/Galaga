
/*
#include "asteroid.hpp"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int x=0, y=0;
    int numberOfAsteroids = 3;
    std::vector<Asteroid> v;
    
    v.resize(numberOfAsteroids);
    //v.resize(10);
    
    initscr();
    noecho();
    curs_set(FALSE);
    
    //  int i = 0;
    //  int j = 0;
    //  do {
    //    j = 0;
    //    do{
    //      clear();
    //      v[i].modY(j);
    //      v[i].setX();
    //      v[i].printAsteroid();
    //      refresh();
    //      j++;
    //    }while (j < 40);
    //    clear();
    //    //v[i].setX();
    //    v[i].setY();
    //    v[i].printAsteroid();
    //    refresh(); 
    //
    //    i++;
    // }while(i < numberOfAsteroids);
    
    for(int i = 0; i < numberOfAsteroids; i++)
    {
        v[i].setX();
        v[i].modY(1);
        v[i].printAsteroid();
    }
    //refresh();
    
    for(int j = 0; j < 40; j++)
    {
        for(int i = 0; i < numberOfAsteroids; i++)
        {
            v[i].modY(v[i].getY() + 1);
        }
        clear();
        for(int i = 0; i < numberOfAsteroids; i++)
        { 
            v[i].printAsteroid(); 
        }
        usleep(200000);
        //refresh();
    }
    
    endwin(); 
} 

*/


