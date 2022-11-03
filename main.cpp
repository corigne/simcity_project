// Authors: GROUP 6
// CSCE2110
// Main function and program loop.
// CURRENTLY MILESTONE 1
// definitions.hpp are object and class definitions
#include "definitions.hpp"
// the rest are functional definitions
#include "file_io.cpp" //author: Trevonne
#include "adjacencies.cpp" //author: Nathan
#include "display.cpp" //author: Salma
#include "update_map.cpp" //author: Chandler
#include "analysis.cpp" //author: Salma, Trevonne

int main(int argc, char *argv[]){
  
  //checks to make sure the user passed a filename argument
  if(argc < 2){
    std::cout << "Please specify an input filename as an argument." << std::endl;
    std::cout << std::endl;
    return 1;
  }

  //the Map is one of two primary data structures, it contains the 2D vector
  Map * city_map = new Map;

  //read file + populate map struct
  //CHANGE THIS BACK TO argv[1] before submission this is for debugging
  std::string config = argv[1];
  fileio(config, city_map->max_time, city_map->refresh_rate, city_map->map_grid);
  city_map->y_size = city_map->map_grid.size();
  city_map->x_size = city_map->map_grid.at(0).size();

  //calculate adjacencies
  calcLocalAdjacencies(city_map);
  calcRemoteAdjacencies(city_map);

  //calculate powered state for the whole map
  for(std::vector<zone*> row : city_map->map_grid)
  {
    for(zone* curr : row)
    {
      //check current type is powerplant, otherwise, nothing needs to be done
      if(curr->getType() == 'P')
      {
        //dynamic casting allows you to call powerplant child functions
        powerplant* pplt_ptr = dynamic_cast<powerplant*>(curr);

        if (pplt_ptr != nullptr)
        {
          //set up the visited/discovery list
          std::vector<bool> vis_temp (city_map->x_size, false);
          std::vector< std::vector<bool> > visited(city_map->y_size, vis_temp);

          //calls recursive setPoweredState, 
          //power radiates out from powerplant to all zones along powerlines
          pplt_ptr->setPoweredState(curr, visited);
        }
      }
    }
  }
  // The zlist is a struct with a working list of resid. , indus., and comm. zones.
  // This is the second primary datastructure primarily for population growth and pollution.
  z_list master_list;
  
  //populate the zlist from the current map
  populate_zlist(*city_map, master_list);

  //FIRST LIST SORT
  //lists are sorted by population, then adj population, then lowest Y, then lowest X
  pop_zone_sort(master_list);

  // Welcome/credit banner:
  std::cout << std::endl
  << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl
  << "~~~ Welcome to SimCity ~~~" << std::endl
  << "~~~ Designed by Group6 ~~~" << std::endl
  << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;

  //Display simulation settings
  std::cout << std::endl << "==== Simulation Settings ====" << std::endl
    << "Refresh Rate: every " << city_map->refresh_rate << " steps"<< std::endl
    << "Max Steps   : " << city_map->max_time << " steps" << std::endl << std::endl;
  
  //Display & Update loop
  int curr_frame = 0;
  bool change = false;

  //primary exit condition for the loop is if current frame == maxtime
  while (curr_frame <= city_map->max_time)
  { 
    //if curr frame is refresh divisible then display the map
    if(curr_frame % city_map->refresh_rate == 0)
    {
      std::cout << "Current Time Step: " << curr_frame << std::endl;
      displayMap(city_map, 0, 0, city_map->x_size-1,city_map->y_size-1);
      std::cout << std::endl;
    }
    
    // updatemap returns true if the map was updated between 2 timesteps
    change = update_map(master_list);

    //pollution updates, recursively, originates from ind nodes
    for(populated* curr : master_list.ind)
    {
      std::list<zone*> q;
      q.push_back(curr);

      std::vector<bool> d_temp (city_map->x_size, false);
      std::vector<std::vector<bool> > disc (city_map->y_size, d_temp);
      disc[curr->getLocation().first][curr->getLocation().second] = true;
      //setup and call of recursive pollution function here
      industrial* temp_ind = dynamic_cast<industrial*>(curr);
      temp_ind->updatePollution(temp_ind, q, disc);
    }

    //update frame counter
    curr_frame += 1; 
    
    //if no updates from last to current time step, break display/update loop...
    if(change == false)
    {
      break;
    }    
  }
  
  // display final pollution values
  displayPollutedMap(city_map, 0, 0, city_map->x_size-1, city_map->y_size-1);
  std::cout << std::endl;

  // begin analysis function lopp
  analysis(city_map, master_list);

  return 0;
}
