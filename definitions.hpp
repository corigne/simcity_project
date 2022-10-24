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
#include "zone.cpp"
#include "unpop_zones.cpp"

struct map{
  std::vector< std::vector<zone> > map_grid;
  int x_size;
  int y_size;
};

//Leave additional useful definitions here.

#endif