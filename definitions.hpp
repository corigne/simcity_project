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
#include "commercial.cpp"
#include "industrial.cpp"
#include "residential.cpp"
#include "unpop_zones.cpp"
#include "adjacencies.cpp"

struct map{
  std::vector< std::vector<zone> > map_grid;
  int x_size;
  int y_size;
};

// TYPEID DEFINITIONS for typeid() comparisons
const std::type_info& EMPTY = typeid(zone());
const std::type_info& ROAD = typeid(road());
const std::type_info& PLINE = typeid(powerline());
const std::type_info& PROAD = typeid(powered_road());
const std::type_info& PPLANT = typeid(powerplant());
const std::type_info& RESIDENTIAL = typeid(residential());
const std::type_info& COMMERCIAL = typeid(commercial());
const std::type_info& INDUSTRIAL = typeid(industrial());

//HELPER FUNCTION TO CONVERT ZONE TO CHAR
char zone_to_char(zone zone)
{
  //if the typeid matches, return the appropriate ascii character
  if(typeid(zone) == EMPTY) return ' ';
  if(typeid(zone) == ROAD) return '-';
  if(typeid(zone) == PLINE) return 'T';
  if(typeid(zone) == PROAD) return '#';
  if(typeid(zone) == PPLANT) return 'P';
  if(typeid(zone) == RESIDENTIAL) return 'R';
  if(typeid(zone) == COMMERCIAL) return 'C';
  if(typeid(zone) == INDUSTRIAL) return 'I';
}
//Leave additional useful definitions here.

#endif