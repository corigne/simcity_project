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

    int getPopulation()
    {
      return this->population;
    }

//This may be moved to update_map.cpp
void IndustiralGrowth(industrial * industryNodeUpdate){
int currentPopulation = industryNodeUpdate->getPopulation();
if(currentPopulation>4)
currentpopulation =4;
switch (currentPopulation){

case 0;
      for(int PGI :  )

break;

  case 1:


break;

  case 2:

break;

  case 3:

break;

  case 4:

break;

  default:

cout<<"Industrial growth update error invalid population retrival"<<endl;

break;
};

   /* void incPopulation()
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

    std::list<zone*> getResidentialAdj()
    {
      return this->residential_adj;
    }
    void setResidentialAdj(std::list<zone*> residentialAdj)
    {
      this->residential_adj = residentialAdj;
    }
};