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
#include "zone.cpp"
#include "unpop_zones.cpp"
#include "adjacencies.cpp"

struct map{
  std::vector< std::vector<zone> > map_grid;
  int x_size;
  int y_size;
};

// TYPEID DEFINITIONS for typeid() comparisons
const type_info& EMPTY = typeid(zone());
const type_info& ROAD = typeid(road());
const type_info& PLINE = typeid(powerline());
const type_info& PROAD = typeid(powered_road());
const type_info& PPLANT = typeid(powerplant());
const type_info& RESIDENTIAL = typeid(residential());
const type_info& COMMERCIAL = typeid(commercial());
const type_info& INDUSTRIAL = typeid(industrial());

//HELPER FUNCTION TO CONVERT ZONE TO CHAR
char zone_to_char(zone zone)
{
  /*
  if(typeid(zone) == zone()){
    return ' ';
  }
  */
}
//Leave additional useful definitions here.

#endif