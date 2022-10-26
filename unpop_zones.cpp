//Author: Nathan Jodoin
//CSCE2110 SimCity
//Recitation Sec. 213 Group 6
//Unpopulated zone class definitions.
#include "definitions.hpp"

//road class
class road: public zone
{
  public:
    road(){

    }
    road(int x, int y)
    {
      setLocation(x, y);
    }

    char getType()
    {
      return '-';
    }
};

//powerline class
class powerline: public zone
{
  public:
    powerline(){

    }
    powerline(int x, int y)
    {
      setLocation(x, y);
    }

    char getType()
    {
      return 'T';
    }
};

//powered_road class
class powered_road: public zone
{
  public:
    powered_road(){

    }
    powered_road(int x, int y)
    {
      setLocation(x, y);
    }

    char getType()
    {
      return '#';
    }
};

//powerplant class
class powerplant: public zone
{
  public:
    powerplant(){
      
    }
    powerplant(int x, int y)
    {
      setLocation(x, y);
    }

    char getType()
    {
      return 'P';
    }
};