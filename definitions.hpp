//Author: Nathan Jodoin
//CSCE2110 - SimCity
//Recitation Section 213 - Group 6
//General definitions to in included almost everywhere.

#ifndef _DEFINITIONS_HPP_
#define _DEFINITIONS_HPP_

#include <utility>
#include <vector>
#include <list>
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
  std::vector< std::vector<zone*> > map_grid;
  int x_size;
  int y_size;
  int refresh_rate;
  int max_time;
} Map;

//Leave additional useful definitions here.

#endif