//Author: Nathan Jodoin
//CSCE2110 - SimCity
//Recitation Section 213 - Group 6
//Adjacency Calculation Functions
#include "definitions.hpp"

void calcLocalAdjacencies(Map * map)
{ 
  for(int y = 0; y < map->y_size; y++)
  {
    for(int x = 0; x < map->x_size; x++)
    {
      //create a temporary vector size 8
      std::vector<zone *> temp;
      temp.reserve(8);

      //if not overwritten a nullptr value represents OUT OF BOUNDS adjacencies
      for(int i = 0; i < 8; i++){
        temp.push_back(nullptr);
      }

      //ALL CELLS ABOVE, indexes 0, 1, and 2
      //OUT OF BOUNDS checking occurs
      if((y - 1) >= 0)
      {
        // if (y - 1, x - 1) is not out of bounds, add top left
        if((x - 1) >= 0)
        {
          temp.at(0) = &(map->map_grid.at(y-1).at(x-1));
        }

        // (y - 1, x), where x is never out of bounds
        temp.at(1) = &(map->map_grid.at(y-1).at(x));

        // (y - 1, x + 1), where x should be < map.x_size
        if((x + 1) < map->x_size)
        {
          temp.at(2) = &(map->map_grid.at(y-1).at(x+1));
        }

      }

      // MIDDLE ADJACENCIES, indexes 3 (left) and 8 (right)
      // no need to check y, as y is never out of bounds

      // left, x - 1 must be >= 0
      if((x - 1) >= 0)
      {
        temp.at(4) = &(map->map_grid.at(y).at(x-1));
      }

      // right, x + 1 must be < x_size
      if((x + 1) < map->x_size)
      {
        temp.at(8) = &(map->map_grid.at(y).at(x+1));
      }

      // BOTTOM ADJACENCIES, indexes 5, 6, and 7 (bot right, bot middle, bot left)
      if((y + 1) < map->y_size)
      {
        // bottom right, x + 1 must be less than x_size
        if((x + 1) < map->x_size)
        {
          temp.at(5) = &(map->map_grid.at(y+1).at(x + 1));
        }

        // middle, where x is never out of bounds
        temp.at(6) = &(map->map_grid.at(y+1).at(x));

        // bottom left, x -1 must be >= 0
        if((x - 1) >= 0)
        {
          temp.at(7) = &(map->map_grid.at(y+1).at(x +1));
        }
      }

      //set zone adj list equal to a copy of the temporary adj list
      map->map_grid.at(y).at(x).setLocallyAdjacent(temp);
    }
  }
}
/*
void calcRemoteAdjacencies()
{
  
}
*/