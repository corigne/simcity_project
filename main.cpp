// main function here
#include "definitions.hpp"
#include "file_io.cpp"
#include "adjacencies.cpp"
#include "display.cpp"

int main(int argc, char *argv[]){
  
  Map * city_map = new Map;
  //read file + populate map struct
  string config = argv[1];
  int time, refresh;
  fileIO(config, time, refresh, map);
  city_map->x_size = city_map->map_grid.size();
  city_map->y_size = city_map->map_grid.at(0).size();

  //calculate adjacencies
  calcLocalAdjacencies(city_map);
  calcRemoteAdjacencies(city_map);

  //calculate power
  for(vector<zone*> row : city_map->map_grid)
  {
    for(zone* curr : row)
    {
      if(curr->getType() == 'P')
      {
        powerplant* pplt_ptr = dynamic_cast<powerplant*>(curr);
        pplt_ptr->setPoweredState(curr);
      }
    }
  }
  //first time display map
  display(city_map);
  //// MILESTONE 1 /////

  //start menu

  //display & update loop

  //analysis

  return 0;
}
