// Authors: GROUP 6
// CSCE2110
// Main function and program loop.
// CURRENTLY MILESTONE 1
#include "definitions.hpp"
#include "file_io.cpp"
#include "adjacencies.cpp"
#include "display.cpp"
#include "update_map.cpp"

int main(int argc, char *argv[]){
  
  Map * city_map = new Map;
  //read file + populate map struct
  //CHANGE THIS BACK TO argv[1] before submission this is for debugging
  std::string config = "config1.txt";
  fileio(config, city_map->max_time, city_map->refresh_rate, city_map->map_grid);
  city_map->y_size = city_map->map_grid.size();
  city_map->x_size = city_map->map_grid.at(0).size();

  //calculate adjacencies by Jodoin, NJ
  calcLocalAdjacencies(city_map);
  calcRemoteAdjacencies(city_map);

  //calculate powered state for the whole map
  for(std::vector<zone*> row : city_map->map_grid)
  {
    for(zone* curr : row)
    {
      if(curr->getType() == 'P')
      {
        //dynamic casting allows you to call powerplant child functions
        powerplant* pplt_ptr = dynamic_cast<powerplant*>(curr);

        if (pplt_ptr != nullptr)
        {
          //set up the visited list
          std::vector<bool> vis_temp (city_map->x_size, false);
          std::vector< std::vector<bool> > visited(city_map->y_size, vis_temp);

          //calls recursive setPoweredState, 
          //power radiates out from powerplant to all zones along powerlines
          pplt_ptr->setPoweredState(curr, visited);
        }
      }
    }
  }
  // The zlist is a struct with a list for residential, industrial, and commercial nodes each.
  // This is the working datastructure for the bulk of the work, such as population updates.
  z_list master_list;
  
  //populate the zlist from the current map
  populate_zlist(*city_map, master_list);
  //FIRST LIST SORT
  pop_zone_sort(master_list);


  //start menu
  //Display simulation settings and prompt user for simulation start.

  // Welcome/credit banner:
  std::cout << std::endl
  << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl
  << "~~~ Welcome to SimCity ~~~" << std::endl
  << "~~~ Designed by Group6 ~~~" << std::endl
  << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;


  char user_in = 0;
  bool validated = false;

  while(!validated)
  {
    // Simulation Settings Confirmation
    std::cout << std::endl << "==== Simulation Settings ====" << std::endl
      << "Refresh Rate: every " << city_map->refresh_rate << " steps"<< std::endl
      << "Max Steps   : " << city_map->max_time << " steps" << std::endl
      << "Start simulation? [(y)es/(c)ancel]: ";

    //user prompt
    
    std::cin >> user_in;
    //validation
    if(std::cin.fail())
    {
      //clears the input error
      std::cin.clear();
      //skips the offending buffer entry for 1 char
      std::cin.ignore();

    }else if(user_in == 'y' || user_in == 'c'){
      //continue simulation
      validated = true;
    }
  }
  //if simulation was cancelled, return from main with 0, intended
  if(user_in == 'c')
  {
    return 0;
  }

  /* TODO

  //display & update loop
  int curr_frame = 0;
  while (curr_frame <= city_map->max_time)
  {
    //updatemap

    //if no update from last frame
  }

  */

  //DEBUG DISPLAY
  displayMap(city_map);

  //analysis

  return 0;
}
