// Author: Nathan Jodoin
// CSCE2110 - Group 6 - Recitation 213
// SimCity: populated zone parent class
#include "definitions.hpp"

class populated: public zone{

  protected:
    int population;
  
  public:
    populated()
    {
      population = 0;
    }
    //returns integer population of zone
    int getPopulation(){
      return this->population;
    }

    //increments population by 1
    void incPopulation(){
      this->population += 1;
    }

};