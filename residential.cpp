// Author: Nathan Jodoin
// CSCE2110 - SimCity
// Recitation Section 213 - Group 6
// Commercial zone Class Def.
#include "definitions.hpp"

class residential : public populated
{
  private:
    int workers;

  public:
    // constructors
    residential()
    {
      this->population = 0;
      this->workers = 0;
    }
    residential(int x, int y)
    {
      this->population = 0;
      this->workers = 0;
      setLocation(x, y);
    }

    // returns the corresponding ASCII character for the zone type
    char getType()
    {
      return 'R';
    }

    int availableWorkers()
    {
      return this->workers;
    }

    //gives the zone +1 worker
    void giveWorker()
    {
      this->workers += 1;
    }

    //removes a worker from the zone (-1 worker)
    void takeWorker()
    {
      this->workers -= 1;
    }

    //returns true if the zone has an available worker
    bool hasWorker()
    {
      if(workers > 0){
        return true;
      }
      return false;
    }
};