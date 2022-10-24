//Author: Nathan Jodoin
//CSCE2110 SimCity
//Recitation Sec. 213 Group 6
//Zone class definition
#include <utility>

class zone
{
  private:
    std::pair<int,int> location;
    int pollution;
    bool powered;
  public:
    //constructor
    zone()
    {
      //if a zone has -1, -1 after intiialization, the location hasn't been set correctly
      location = std::pair<int,int>(-1,-1);
      pollution = 0;
      powered = false;
    }

    //Accessors
    std::pair<int,int> getLocation() const
    {
      return this->location;
    }
    int getPolution() const
    {
      return this->pollution;
    }
    bool isPowered() const{
      return this->powered;
    }

    //Mutators
    void setLocation(int X, int Y)
    {
      this->location.first = X;
      this->location.second = Y;
    }
    void setPollution(int pollutionVal)
    {
      this->pollution = pollutionVal;
    }
    void setPowered(bool isPoweredOrNot){
      this->powered = isPoweredOrNot;
    }
};