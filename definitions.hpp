//Author: Nathan Jodoin
//CSCE2110 - SimCity
//Recitation Section 213 - Group 6
//General definitions to in included almost everywhere.

#ifndef _DEFINITIONS_HPP_
#define _DEFINITIONS_HPP_

#include <utility>
#include <vector>
#include <iostream>
#include <iomanip>
#include <typeinfo>
// class includes here
// avoid functional includes here
#include "zone.cpp"
#include "unpop_zones.cpp"
#include "commercial.cpp"
#include "industrial.cpp"
#include "residential.cpp"

typedef struct Map
{
  std::vector< std::vector<zone> > map_grid;
  int x_size = -1;
  int y_size = -1;
} Map;

//HELPER FUNCTION TO CONVERT zone TO CHAR
char zone_to_char(zone& input)
{
  //if the typeid matches, return the appropriate ascii character
  if(typeid(input) == typeid(road))
  {
    return '-';
  }
  if(typeid(input) == typeid(powerline))
  {
    return 'T';
  }
  if(typeid(input) == typeid(powered_road))
  {
    return '#';
  }
  if(typeid(input) == typeid(powerplant))
  {
    return 'P';
  }
  if(typeid(input) == typeid(residential))
  {
    return 'R';
  }
  if(typeid(input) == typeid(commercial))
  {
    return 'C';
  }
  if(typeid(input) == typeid(industrial))
  {
    return 'I';
  }
  //has to be at the end bc technically all children are zones
  if(typeid(input) == typeid(zone))
  {
    return ' ';
  }
  //returns for error
  return 'e';
}
//Leave additional useful definitions here.

#endif