//Author: Nathan Jodoin
//CSCE2110 SimCity
//Recitation Sec. 213 Group 6
//zone class definition

class zone
{
  private:
    std::pair<int,int> location;
    int pollution;
    //I moved these to public so my power function can access them - chandler
    bool powered;
    //local adjacency list, should be reserved size 8 in constructor
    std::vector<zone*> locallyAdjacent;

  public:
    //constructor
    zone()
    {
      //if a zone has -1, -1 after intiialization, the location hasn't been set correctly
      location = std::pair<int,int>(-1,-1);
      pollution = 0;
      powered = false;

      //reserve 8 spots for the local adjacencies
      this->locallyAdjacent.reserve(8);
    }
    zone(int x_loc, int y_loc)
    {
      location = std::pair<int,int>(x_loc, y_loc);
      pollution = 0;
      powered = false;
      this->locallyAdjacent.reserve(8);
    }

    //Accessors
    virtual char getType()
    {
      return ' ';
    }
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
    std::vector<zone*> getLocallyAdjacent() const
    {
      return this->locallyAdjacent;
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
    void setLocallyAdjacent(std::vector<zone*> locallyAdjacentNodes){
      //remember this must be size 8, top left adjacent first
      this->locallyAdjacent = locallyAdjacentNodes;
    }
};