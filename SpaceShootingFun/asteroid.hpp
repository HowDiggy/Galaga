//asteroid.h


#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <vector>
#include <cstdlib>



class Asteroid{
private:
  int x, y, xMax, xMin, yMax;
  char character;

public:
  Asteroid();
  void setY();
  void setX();
  int getY();
  int getX();
  void modY(int i);


  void printAsteroid();



};
