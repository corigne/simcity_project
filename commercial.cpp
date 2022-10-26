// Author: Nathan Jodoin
// CSCE2110 - SimCity
// Recitation Section 213 - Group 6
// Commercial zone Class Def.
#include "definitions.hpp"

class commercial : public zone
{
  private:
    int population;

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

    char getType() override
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
};