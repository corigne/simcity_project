// Authors: GROUP 6
// CSCE2110
// Main function and program loop.
// CURRENTLY MILESTONE 1
#include "definitions.hpp"
#include "file_io.cpp"
#include "adjacencies.cpp"
#include "display.cpp"

int main(int argc, char *argv[]){
  
  Map * city_map = new Map;
  //read file + populate map struct
  //CHANGE THIS BACK TO argv[1] before submission this is for debugging
  string config = "config1.txt";
  fileio(config, city_map->max_time, city_map->refresh_rate, city_map->map_grid);
  city_map->y_size = city_map->map_grid.size();
  city_map->x_size = city_map->map_grid.at(0).size();

  //calculate adjacencies by Jodoin, NJ
  
  // currently throwing error due to vector sizing
  calcLocalAdjacencies(city_map);
  calcRemoteAdjacencies(city_map);

  //calculate powered state for the whole map
  for(vector<zone*> row : city_map->map_grid)
  {
    for(zone* curr : row)
    {
      if(curr->getType() == 'P')
      {
        //dynamic casting allows you to call powerplant child functions
        powerplant* pplt_ptr = dynamic_cast<powerplant*>(curr);

        vector<bool> vis_temp (city_map->x_size, false);
        vector< vector<bool> > visited(city_map->y_size, vis_temp);
        pplt_ptr->setPoweredState(curr, visited);
      }
    }
  }

  //first time display map
  displayMap(city_map);
  
  //// MILESTONE 1 COMPLETED/////

  //start menu

  //display & update loop

  //analysis

  return 0;
}
