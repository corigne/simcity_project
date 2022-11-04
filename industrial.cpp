// Author: Nathan Jodoin
// CSCE2110 - SimCity
// Recitation Section 213 - Group 6
// industrial zone Class Def. inherits from populated << zone
#include "definitions.hpp"

class industrial : public populated
{
  private:
    int goods;
    //residential adjacency list, by distance
    std::list<residential*> residential_adj;
  public:
    //constructors
    industrial()
    {
      this->population = 0;
      this->goods = 0;
    }
    //primary working constructor for passing in X, Y coords
    industrial(int x, int y)
    {
      this->population = 0;
      this->goods = 0;
      setLocation(x, y);
    }

    //returns the correct ASCII char for the zone type
    char getType()
    {
      return 'I';
    }

    //returns true is the zone has available goods
    bool hasGoods()
    {
      if(goods > 0)
      {
        return true;
      }
      return false;
    }

    //returns the total # of available goods
    int availableGoods()
    {
      return this->goods;
    }

    //gives this zone a good (+1)
    void addGoods()
    {
      this->goods += 1;
    }

    //takes a good from the zone (-1)
    void sendGoods()
    {
      this->goods -= 1;
    }

    //returns the list of residential adjacencies by distance
    std::list<residential*> getResidentialAdj()
    {
      return this->residential_adj;
    }

    //set the residential adjacency list
    void setResidentialAdj(std::list<residential*> residentialAdj)
    {
      this->residential_adj = residentialAdj;
    }

    /// @brief Recursive BFS traversal of adjacent zone* to set pollution
    /// @param org 
    /// @param q 
    /// @param disc 
    void updatePollution(industrial* &org, std::list<zone*> &q,
       std::vector<std::vector<bool> > &disc)
    {

      //if disc q empty return stack
      if(q.empty())
      {
        return;
      }
      
      zone* curr = q.front();
      q.pop_front();

      //initial case, set pollution level of industrial zone
      if(curr == org)
      {
        curr->setPollution(org->getPopulation());
      }

      //set the pollution level for the adj zones
      int poll_lvl = curr->getPollution() - 1;

      //traverse to all zones adjacent and add undisc zones to the disc q
      for(zone* adj : curr->getLocallyAdjacent())
      {
        if(adj != nullptr)
        {
          int x = adj->getLocation().first;
          int y = adj->getLocation().second;

          if(!disc[x][y])
          {
            //  if not yet updated, update neighbors with pollution
            // but only if the poll_lvl is higher than the existing poll lvl
            //  doing this with BFS the poll. is set according to BFS lvl
            if(poll_lvl > adj->getPollution())
            {
              adj->setPollution(poll_lvl);
            }
            //add the adj to the disc q and add it to the disc map
            q.push_back(adj);
            disc[x][y] = true;
          }
        }
      }
      //recursive step to the next zone in the disc q
      updatePollution(org, q, disc);
    }
};