//Author: Nathan Jodoin
//CSCE2110 SimCity
//Recitation Sec. 213 Group 6
//Unpopulated zone class definitions.
#include "definitions.hpp"
//road class
class road: public zone
{
  public:
    road(){

    }
    road(int x, int y)
    {
      setLocation(x, y);
    }

    char getType()
    {
      return '-';
    }
};

//powerline class
class powerline: public zone
{
  public:
    powerline(){

    }
    powerline(int x, int y)
    {
      setLocation(x, y);
    }

    char getType()
    {
      return 'T';
    }
};

//powered_road class
class powered_road: public zone
{
  public:
    powered_road(){

    }
    powered_road(int x, int y)
    {
      setLocation(x, y);
    }

    char getType()
    {
      return '#';
    }
};
//powerplant class
class powerplant: public zone
{
  public:
<<<<<<< HEAD


    void setPoweredState(zone * currentZone){

        for(zone *PSI :currentZone->getLocallyAdjacent() ){
            if(PSI ==nullptr||PSI->getType()=='-')
            continue;
            else{setPoweredState(PSI);}

    }


    }

=======
    //Constructor
>>>>>>> 5fa49874fd122a0b61be5c5b8e8d1665044b7cc3
    powerplant(){
      
    }
    powerplant(int x, int y)
    {
      setLocation(x, y);
    }

    // this template allows the user to pass an array w/o size
    
    void setPoweredState(zone* cell, std::vector<std::vector<bool> > (&visited)){
      
      cell->setPowered(true);
      visited[cell->getLocation().second][cell->getLocation().first] = true;

      for(zone *PSI : cell->getLocallyAdjacent()){
        
        //if PSI is adjacent to the powerline, powered road, or powerplant, it has power
        if(PSI != NULL)
        { 
          PSI->setPowered(true);
        }else{ //if NULL, continue to next zone
          continue;
        }

        //TRAVERSAL TO NEXT POWERLINE BY DFS RECUSIVELY
        if(!(PSI->getType() == 'T' || PSI->getType() == '#'))
        {
          continue;
        }
        else
        {
          //if not visited, visit next node
          if(!(visited[PSI->getLocation().second][PSI->getLocation().first]))
           { 
            setPoweredState(PSI, visited);
           }
        }
      }
    }

    char getType()
    {
      return 'P';
    }
};