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
          temp.at(0) = map->map_grid.at(y-1).at(x-1);
        }

        // (y - 1, x), where x is never out of bounds
        temp.at(1) = map->map_grid.at(y-1).at(x);

        // (y - 1, x + 1), where x should be < map.x_size
        if((x + 1) < map->x_size)
        {
          temp.at(2) = map->map_grid.at(y-1).at(x+1);
        }

      }

      // MIDDLE ADJACENCIES, indexes 3 (left) and 7 (right)
      // no need to check y, as y is never out of bounds

      // left, x - 1 must be >= 0
      if((x - 1) >= 0)
      {
        temp.at(7) = map->map_grid.at(y).at(x-1);
      }

      // right, x + 1 must be < x_size
      if((x + 1) < map->x_size)
      {
        temp.at(3) = map->map_grid.at(y).at(x+1);
      }

      // BOTTOM ADJACENCIES, indexes 4, 5, and 6 (bot right, bot middle, bot left)
      if((y + 1) < map->y_size)
      {
        // bottom right, x + 1 must be less than x_size
        if((x + 1) < map->x_size)
        {
          temp.at(4) = map->map_grid.at(y+1).at(x+1);
        }

        // middle, where x is never out of bounds
        temp.at(5) = map->map_grid.at(y+1).at(x);

        // bottom left, x -1 must be >= 0
        if((x - 1) >= 0)
        {
          temp.at(6) = map->map_grid.at(y+1).at(x-1);
        }
      }

      //set zone adj list equal to a copy of the temporary adj list
      map->map_grid.at(y).at(x)->setLocallyAdjacent(temp);
    }
  }
}

void zoneBFS(Map * city, zone * origin)
{
  //we don't need remote adjacencies for non Comm and Industrial nodes
  if(origin->getType() == 'C' || origin->getType() == 'I')
  {
    std::list<residential*>* temp_res = new std::list<residential*>;
    std::list<industrial*>* temp_ind = new std::list<industrial*>;
    //this array with the same bounds as the city provides O(n)=1 truth checking for visited condition
    bool visited[city->x_size][city->y_size];
    //used as a queue to track nodes to visit
    std::list<zone*> discQueue;
    discQueue.push_back(origin);

    //add origin to visited
    int origin_X = origin->getLocation().first;
    int origin_Y = origin->getLocation().second;
    visited[origin_X][origin_Y] = true;
    //then start BFS traversal
    while(!(discQueue.empty()))
    {
      zone* curr = discQueue.front();
      char curr_type = curr->getType();
      discQueue.pop_front();
      // traverse adjacent nodes to the current node
      // add traversable adjacent nodes to the discovery queue
      // note: CAN traverse along roads, powered_roads, and R/C/I/P
      for(zone* adj : curr->getLocallyAdjacent())
      {
        if(adj != nullptr)
        {

        int x = adj->getLocation().first;
        int y = adj->getLocation().second;
        //If adj was not visited, and is not null add it to the disc queue.
        
          if(visited[x][y] != true)
          {
            if((adj->getType() != 'T') || (adj->getType() != ' '))
            {
              discQueue.push_back(adj);
              visited[x][y] = true;
            }
          }
        }
      }

      // if current isn't the origin, and origin is a Commercial or Industrial
      // add residential and industrial nodes to the correct lists
      if(curr != origin)
      {
        if(curr->getType() == 'R')
        {
          residential* temp_r = dynamic_cast<residential*>(curr);
          temp_res->push_back(temp_r);
        }
        if(curr->getType() == 'I')
        {
          industrial* temp_i = dynamic_cast<industrial*>(curr);
          temp_ind->push_back(temp_i);
        }  
      }
    }

    //add the appropriate lists by dynamic casting
    if(origin->getType() == 'I')
    {
      industrial* temp_i = dynamic_cast<industrial*>(origin);
      temp_i->setResidentialAdj(*temp_res);
    }

    if(origin->getType() == 'C')
    {
      commercial* temp_c = dynamic_cast<commercial*>(origin);
      temp_c->setResidentialAdj(*temp_res);
      temp_c->setIndustrialAdj(*temp_ind);
    }
  }
}

void calcRemoteAdjacencies(Map * map)
{
  for(std::vector<zone*> rows : map->map_grid)
  {
    for(zone* curr : rows)
    {
      zoneBFS(map, curr);
    }
  }
}