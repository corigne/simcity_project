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
#include "commercial.cpp"
#include "industrial.cpp"
#include "residential.cpp"
#include "unpop_zones.cpp"

typedef struct Map
{
  std::vector< std::vector<zone> > map_grid;
  int x_size = -1;
  int y_size = -1;
} Map;


// TYPEID DEFINITIONS for typeid() comparisons
const std::type_info& EMPTY = typeid(zone);
const std::type_info& ROAD = typeid(road);
const std::type_info& PLINE = typeid(powerline);
const std::type_info& PROAD = typeid(powered_road);
const std::type_info& PPLANT = typeid(powerplant);
const std::type_info& RESIDENTIAL = typeid(residential);
const std::type_info& COMMERCIAL = typeid(commercial);
const std::type_info& INDUSTRIAL = typeid(industrial);

//HELPER FUNCTION TO CONVERT zone TO CHAR
char zone_to_char(zone input)
{
  //if the typeid matches, return the appropriate ascii character
  if(typeid(input) == ROAD)
  {
    return '-';
  }
  if(typeid(input) == PLINE)
  {
    return 'T';
  }
  if(typeid(input) == PROAD)
  {
    return '#';
  }
  if(typeid(input) == PPLANT)
  {
    return 'P';
  }
  if(typeid(input) == RESIDENTIAL)
  {
    return 'R';
  }
  if(typeid(input) == COMMERCIAL)
  {
    return 'C';
  }
  if(typeid(input) == INDUSTRIAL)
  {
    return 'I';
  }
  //has to be at the end bc technically all children are zones
  if(typeid(input) == EMPTY)
  {
    return ' ';
  }
  //returns for error
  return 'e';
}
//Leave additional useful definitions here.

#endif