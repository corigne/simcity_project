// Author: Nathan Jodoin
// CSCE2110 - SimCity
// Recitation Section 213 - Group 6
// Commercial zone Class Def.
#include "definitions.hpp"

class commercial : public populated
{
  private:
    std::list<residential*> residentialAdj;
    std::list<industrial*> industrialAdj;

  public:
    //constructors
    commercial()
    {
      this->population = 0;
    }
    //primary working constructor
    commercial(int x, int y)
    {
      setLocation(x, y);
      this->population = 0;
    }
    
    // returns the corresponding ASCII character for the zone type
    char getType()
    {
      return 'C';
    }

    //returns a list of residential Adjacencies in order of distance
    std::list<residential*> getResidentialAdj()
    {
      return this->residentialAdj;
    }

    // set the residential adjacencies
    void setResidentialAdj(std::list<residential*> residentialAdj)
    {
      this->residentialAdj = residentialAdj;
    }

    //returns a list of industrial zone adjacencies
    std::list<industrial*> getIndustrialAdj()
    {
      return this->industrialAdj;
    }

    //set the industrial adjacency list
    void setIndustrialAdj(std::list<industrial*> industrialAdj)
    {
      this->industrialAdj = industrialAdj;
    }
};