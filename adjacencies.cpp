//Author: Nathan Jodoin
//CSCE2110 - SimCity
//Recitation Section 213 - Group 6
//Adjacency Calculation Functions
#include "definitions.hpp"

/// @brief Creates a vector of local adjacencies, starting with topleft going clockwise
/// @param map is the primary datastructure required to identify local adjacencies
void calcLocalAdjacencies(Map * map)
{ 
  //for each row in the map
  for(int y = 0; y < map->y_size; y++)
  {
    //for each zone in the row
    for(int x = 0; x < map->x_size; x++)
    {
      //create a temporary vector size 8
      std::vector<zone *> temp;
      temp.reserve(8);

      // a nullptr value represents OUT OF BOUNDS adjacencies
      // so we will the vector with nullptr by default
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

/// @brief Recursively builds an adjlist of resid. and incust. pointers from the origin
/// @param q the shared discovery queue, passed in with origin already inside
/// @param r empty list  residential* adjacencies by dist
/// @param i empty list for industrial* adjacencies by dist
/// @param disc discovery truth map, 2D array of bool (X,Y)
void zoneBFS(std::list<zone*> &q, std::list<residential*> &r,
  std::list<industrial*> &i, std::vector<std::vector<bool> > (&disc))
{
  //if the queue is empty, there are no more traversable zones, return up the stack
  if(q.empty())
  {
    return;
  }

  zone* curr = q.front();
  
  // if current is a residential or industrial, add to appropriate list
  switch(curr->getType())
  {
    case 'I':
    {
      //dynamic casting allows us to push back an industrial pointer to the list
      industrial* tmp_curr = dynamic_cast<industrial*>(curr);
      i.push_back(tmp_curr);
      break;
    }
    case 'R':
    {
      //dynamic casting again, same reason
      residential* tmp_curr = dynamic_cast<residential*>(curr);
      r.push_back(tmp_curr);
      break;
    }
    default:
    {
      break;
    }
  }

  // pop the front of the disc queue
  q.pop_front();

  // for each adjacent of the current zone, add traversable zones to the disc q
  for(zone* adj : curr->getLocallyAdjacent())
  {
    if(adj != nullptr)
    {
      int x = adj->getLocation().first;
      int y = adj->getLocation().second;
      bool trav = ((adj->getType() != ' ') && (adj->getType() != 'T'));
      
      if(trav && !disc[x][y])
      {
        disc[x][y] = true;
        q.push_back(adj);
      }
    }
  }
  //then recurse to the next item in the queue
  zoneBFS(q, r, i, disc);
}

/// @brief The master function from which the remote adj BFS algo is called
/// @param map the working Map passed in from main
void calcRemoteAdjacencies(Map * map)
{
  //for each row/zone in the map, run BFS to build the adjacency list
  for(std::vector<zone*> rows : map->map_grid)
  {
    for(zone* curr : rows)
    { 
      std::list<residential*> res;
      std::list<industrial*> ind;
      std::list<zone*> q;
      std::vector<bool> disc_temp (map->x_size, false);
      std::vector< std::vector<bool> > disc(map->y_size, disc_temp);

      disc[curr->getLocation().first][curr->getLocation().second] = true;
      q.push_back(curr);

      zoneBFS(q, res, ind, disc);

      //if the current zone is indust. or comm. pass in their required adj lists
      if(curr->getType() == 'I')
      {
        //dyanamic casting required here too
        industrial* temp_i = dynamic_cast<industrial*>(curr);
        temp_i->setResidentialAdj(res);
      }
      if(curr->getType() == 'C')
      {
        //and here again
        commercial* temp_c = dynamic_cast<commercial*>(curr);
        temp_c->setResidentialAdj(res);
        temp_c->setIndustrialAdj(ind);
      }
    }
  }
}