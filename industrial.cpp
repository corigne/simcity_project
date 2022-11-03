// Author: Nathan Jodoin
// CSCE2110 - SimCity
// Recitation Section 213 - Group 6
// industrial zone Class Def.
#include "definitions.hpp"

class industrial : public populated
{
  private:
    int goods;
    //residential adjacency list, by distance
    std::list<residential*> residential_adj;
  public:
    //constructor
    industrial()
    {
      this->population = 0;
      this->goods = 0;
    }
    industrial(int x, int y)
    {
      this->population = 0;
      this->goods = 0;
      setLocation(x, y);
    }

    char getType()
    {
      return 'I';
    }

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

    void updatePollution()
    {
      //set starting values
      zone* origin = this;
      this->setPollution(this->getPopulation());
      int poll_lvl = this->getPollution();

      std::vector<std::vector<bool> > visited;
      std::list<zone*> disc_q;

      //add origin to the disc queue and mark it visited
      disc_q.push_back(origin);
      visited[this->getLocation().first][this->getLocation().second] = true;
      
      while(disc_q.empty() != true)
      {
        zone* current = &*disc_q.front();
        disc_q.pop_front();

        for(zone* adj : current->getLocallyAdjacent())
        {
          //ignores zones that don't exist (Out of Bounds) and already "visited"
          if(adj!=nullptr && visited[adj->getLocation().first][adj->getLocation().second]!=true)
          {  
            //don't update the pollution of another industrial zone
            if(!(adj->getType() == 'I'))
            {
              //if curr pollution is 0 BFS is done
              if(!(current->getPollution() == 0))
              {
                //set poll of adjacent node only if poll-1 is > existing pollution
                if(adj->getPollution() < current->getPollution() - 1)
                {
                  adj->setPollution(current->getPollution() - 1);
                }
                
              }else
              {
                break;
              }
            }
          }
        }
      }
    }
};