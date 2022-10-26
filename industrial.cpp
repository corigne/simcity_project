// Author: Nathan Jodoin
// CSCE2110 - SimCity
// Recitation Section 213 - Group 6
// industrial zone Class Def.
#include "definitions.hpp"

class industrial : public zone
{
  private:
    int population;
    int goods;

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

    int getPopulation()
    {
      return this->population;
    }

    void incPopulation()
    {
      this->population += 1;
    }

    bool hasGoods()
    {
      if(goods > 0)
      {
        return true;
      }
      return false;
    }

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

};