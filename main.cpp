// Authors: GROUP 6
// CSCE2110
// Main function and program loop.
// CURRENTLY MILESTONE 1
#include "definitions.hpp"
#include "file_io.cpp"
#include "adjacencies.cpp"
#include "display.cpp"
#include "update_map.cpp"
using namespace std;

// REMOVE ME
void print_adjacencies(Map * map)
{
  int i, y = 0, x = 0;
  for(vector<zone*> row : map->map_grid)
  {
    
    for(zone* zones : row)
    {
      i = 0;
      cout << y << ", " << x << ": Local: ";
      for(zone * adjacent : zones->getLocallyAdjacent())
      {
        if(adjacent != nullptr){
          cout << i << ": " << adjacent->getType() << " ";
        }else
        {
          cout << i << ": " << "OOB "; 
        }
        i++;
      }
      cout << endl;

      //print remote adjacencies
      if(zones->getType() == 'C' || zones->getType() == 'I')
      {
        cout << "|Remote: ";
        switch(zones->getType())
        {
          case 'C':
            i = 0;
            cout << endl <<  "|| Residential: ";
            for(zone* curr : dynamic_cast<commercial*>(zones)->getResidentialAdj())
            {
              cout << i << ": " << curr->getType() << " ";
              i++;
            }
            cout << endl << "|| Industrial: ";
            for(zone* curr : dynamic_cast<commercial*>(zones)->getIndustrialAdj())
            {
              cout << i << ": " << curr->getType() << " ";
              i++;
            }
            break;
          
          case 'I':
            i = 0;
            cout << endl <<  "|| Residential: ";
            for(zone* curr : dynamic_cast<industrial*>(zones)->getResidentialAdj())
            {
              cout << i << ": " << curr->getType() << " ";
              i++;
            }
            break;
        }
        cout << endl;
      }
      
      x++;
    }
    x = 0;
    y++;
  }
}

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

  print_adjacencies(city_map);

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

  std::cout << std::endl << "==== Simulation Settings ====" << std::endl
    << "Refresh Rate: every " << city_map->refresh_rate << " steps"<< std::endl
    << "Max Steps   : " << city_map->max_time << " steps" << std::endl;
  
  /*
  char user_in = 0;
  bool validated = false;

  while(!validated)
  {
    // Simulation Settings Confirmation
 
    std::cout << "Start simulation? [(y)es/(c)ancel]: ";

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
*/

  //display & update loop
  int curr_frame = 0;
  bool change = false;

  while (curr_frame <= city_map->max_time)
  { 
    //if (refresh divisible) then: display post-update
    if(curr_frame % city_map->refresh_rate == 0)
    {
      std::cout << "Current Time Step: " << curr_frame << std::endl;
      displayMap(city_map);
      std::cout << std::endl;
    }
    
    //updatemap should return true if nothing was updated between 2 timesteps
    // else it should return false
    change = update_map(master_list);

    /*
    //pollution updates
    for(populated* curr : master_list.ind)
    {
      industrial* temp_ind = dynamic_cast<industrial*>(curr);
      temp_ind->updatePollution();
    }
    */

    //update frame
    curr_frame += 1; 
    
    //if no updates in from last to current time step, break display/update loop...
    if(change == false)
    {
      break;
    }    
  }

  //...and begin analysis


  return 0;
}
