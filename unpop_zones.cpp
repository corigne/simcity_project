//Author: Nathan Jodoin
//CSCE2110 SimCity
//Recitation Sec. 213 Group 6
//Unpopulated zone class definitions.
#include "definitions.hpp"
<<<<<<< HEAD

=======
/*
>>>>>>> bc6c626524711bf36c86fa24f6ddad76f94e52c2
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
<<<<<<< HEAD

=======
*/
>>>>>>> bc6c626524711bf36c86fa24f6ddad76f94e52c2
//powerplant class
class powerplant: public zone
{
  public:

<<<<<<< HEAD
    setPoweredState(*zone){

        for(zone PSI :zone.adjacencyList ){
            if(PSI ==NULL||zone.getType()=='-')
            continue;
            else{setPoweredState(*PSI}
=======
   void setPoweredState(zone *cell){
        cell->powered=true;
        
        for(zone *PSI : cell->locallyAdjacent){
            if(PSI == NULL||PSI->getType()=='-')
            continue;

            else{setPoweredState(PSI);}
>>>>>>> bc6c626524711bf36c86fa24f6ddad76f94e52c2
    }


    }

    powerplant(){
      
    }
    powerplant(int x, int y)
    {
      setLocation(x, y);
    }

    char getType()
    {
      return 'P';
    }

};