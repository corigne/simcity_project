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
#include <fstream>

// class includes here
// avoid functional includes here
#include "zone.cpp"
#include "populated.cpp"
#include "unpop_zones.cpp"
#include "residential.cpp"
#include "industrial.cpp"
#include "commercial.cpp"


typedef struct Map
{
  std::vector< std::vector<zone*> > map_grid;
  int x_size;
  int y_size;
  int refresh_rate;
  int max_time;
} Map;

typedef struct z_list
{
  //residential list
  std::vector<populated *> res;

  //industrial list
  std::vector<populated *> ind;

  //commerical list
  std::vector<populated*> com;
  
} z_list;

//Leave additional useful definitions here.
#endif