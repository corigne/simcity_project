// Author: Nathan Jodoin
// CSCE2110 - SimCity
// Recitation Section 213 - Group 6
// Commercial zone Class Def.
#include "definitions.hpp"

class commercial : public populated
{
  private:
    std::list<zone*> residentialAdj;
    std::list<zone*> industrialAdj;

  public:
    commercial()
    {
      this->population = 0;
    }
    commercial(int x, int y)
    {
      setLocation(x, y);
      this->population = 0;
    }

    char getType()
    {
      return 'C';
    }

    //returns a list of residential Adjacencies in order of distance
    std::list<zone*> getResidentialAdj()
    {
      return this->residentialAdj;
    }

    // set the residential adjacencies
    void setResidentialAdj(std::list<zone*> residentialAdj)
    {
      this->residentialAdj = residentialAdj;
    }

    //returns a list of industrial zone adjacencies
    std::list<zone*> getIndustrialAdj()
    {
      return this->industrialAdj;
    }

    //set the industrial adjacency list
    void setIndustrialAdj(std::list<zone*> industrialAdj)
    {
      this->industrialAdj = industrialAdj;
    }
};