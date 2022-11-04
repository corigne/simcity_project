//Author: Nathan Jodoin
//CSCE2110 SimCity
//Recitation Sec. 213 Group 6
//Unpopulated zone class definitions, most of them are just placeholders.
//They're primarily used to to typechecking for adjacency traversals.
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

// powerplant class
// This was originally intended to be a major component of our program functionality,
// however the project requirements have no function for the powerplant
// Chandler and I coded the powerline traversal functionality into the program 
// before the functionality was deemed unnecessary. ~Nathan J.

class powerplant: public zone
{
  public:

    // Description: uses recursive DFS to traverse along powerlines and powered roads
    // any zone adjacent to a powerplant, powerline, or powered road will have
    // its powered state set to true.
    void setPoweredState(zone * currentZone){

      for(zone *PSI :currentZone->getLocallyAdjacent() )
      {
          if(PSI ==nullptr||PSI->getType()=='-')
          continue;
          else{setPoweredState(PSI);}
      }
    }

    powerplant(){}

    powerplant(int x, int y)
    {
      setLocation(x, y);
    }

    void setPoweredState(zone* cell, std::vector<std::vector<bool> > (&visited))
    {
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

    //Returns the appropriate ASCII character for the zone type
    char getType()
    {
      return 'P';
    }
};