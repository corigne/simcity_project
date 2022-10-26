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
    explicit commercial(int x, int y) : zone(x, y)
    {
      this->population = 0;
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