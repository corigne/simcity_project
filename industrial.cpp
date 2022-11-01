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
    std::list<zone *> residential_adj;
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
    std::list<zone*> getResidentialAdj()
    {
      return this->residential_adj;
    }

    //set the residential adjacency list
    void setResidentialAdj(std::list<zone*> residentialAdj)
    {
      this->residential_adj = residentialAdj;
    }
};