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