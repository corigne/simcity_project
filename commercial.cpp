// Author: Nathan Jodoin
// CSCE2110 - SimCity
// Recitation Section 213 - Group 6
// Commercial zone Class Def.
#include "definitions.hpp"

class commercial : public zone
{
  private:
    int population;
    std::list<zone*> residentialAdj;
    std::list<zone*> industrialAdj;

  public:
    commercial()
    {
      population = 0;
    }
    commercial(int x, int y)
    {
      population = 0;
      setLocation(x, y);
    }

    char getType()
    {
      return 'C';
    }
    
    int getPopulation()
    {
      return this->population;
    }
    void incPopulation()
    {
      this->population += 1;
    }
    std::list<zone*> getResidentialAdj()
    {
      return this->residentialAdj;
    }
    void setResidentialAdj(std::list<zone*> residentialAdj)
    {
      this->residentialAdj = residentialAdj;
    }
    std::list<zone*> getIndustrialAdj()
    {
      return this->industrialAdj;
    }
    void setIndustrialAdj(std::list<zone*> industrialAdj)
    {
      this->industrialAdj = industrialAdj;
    }
};