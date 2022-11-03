//Author: Nathan Jodoin
//CSCE2110 - SimCity
//Recitation Section 213 - Group 6
//General definitions the need to be included almost everywhere.

#ifndef _DEFINITIONS_HPP_
#define _DEFINITIONS_HPP_

#include <utility>
#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <fstream>

// class includes here
// avoid functional includes here
#include "zone.cpp" // Author: Nathan 
#include "populated.cpp" // Author: Nathan 
#include "unpop_zones.cpp" // Author: Nathan 
#include "residential.cpp" // Author: Nathan 
#include "industrial.cpp" // Author: Nathan 
#include "commercial.cpp" // Author: Nathan 

// type definition for the Map type, the primary working datastructure
typedef struct Map
{
  // a 2D vector of zone* which represents the map
  std::vector< std::vector<zone*> > map_grid;
  // X and Y size of the map, useful for other functions, primarily bounding
  int x_size;
  int y_size;
  // data members for the simulation settings, read in from the config file
  int refresh_rate;
  int max_time;
} Map;

// type def for the second primary data structure, the zlist is a struct of 3
// populated* vectors representing each of the class types which needs to be check for 
// population update conditions in an ordered manner, these are sorted
typedef struct z_list
{
  //residential zone list
  std::vector<populated *> res;

  //industrial zone list
  std::vector<populated *> ind;

  //commerical zone list
  std::vector<populated*> com;
  
} z_list;

#endif