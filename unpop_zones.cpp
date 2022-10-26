//Author: Nathan Jodoin
//CSCE2110 SimCity
//Recitation Sec. 213 Group 6
//Unpopulated zone class definitions.
#include "definitions.hpp"

//road class
class road: public zone
{
  public:
    explicit road(int x, int y) : zone(x, y) {}
    
};

//powerline class
class powerline: public zone
{
  public:
    explicit powerline(int x, int y) : zone(x, y) {}
};

//powered_road class
class powered_road: public zone
{
  public:
    explicit powered_road(int x, int y) : zone(x, y) {}
};

//powerplant class
class powerplant: public zone
{
  public:
    explicit powerplant(int x, int y) : zone(x, y) {}
};