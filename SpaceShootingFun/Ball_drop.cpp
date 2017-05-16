#include "asteroid.hpp"


int main(int argc, char *argv[]) {
 int x=0, y=0;
 int numberOfAsteroids = 10000;
 std::vector<Asteroid> v;

v.resize(numberOfAsteroids);

 //v.resize(10);

 initscr();
 noecho();
 curs_set(FALSE);

 int i = 0;
 int j = 0;
 do {
j = 0;
   do{
     clear();
     v[i].modY(j);
     v[i+1].modY(j);
     v[i].setX();
     v[i+1].setX();
     v[i].printAsteroid();
     v[i+1].printAsteroid();
     refresh();
     j++;
   }while (j < 40);
clear();
//v[i].setX();
v[i].setY();
v[i+1].setY();
v[i].printAsteroid();
v[i+1].printAsteroid();
refresh();

i++;
}while(i < numberOfAsteroids);

 endwin();
}
