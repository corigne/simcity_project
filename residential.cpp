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

    bool hasWorker()
    {
      if(workers > 0){
        return true;
      }
      return false;
    }
};