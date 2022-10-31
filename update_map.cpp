#include "definitions.hpp"

// update function definitions here

//residential
bool residentialGrowthCheck(residential * residentialZone)
{
  int PopCounterResidential = 0;
  int residentialZonePop = residentialZone->getPopulation();
switch(residentialZonePop){

case 0:
for(zone * RGI :residentialZone->getLocallyAdjacent() )
{
  if(RGI->getType()=='T')
  {
  return true;
  }

}
for(zone * RGI : residentialZone->getLocallyAdjacent())
{

  if(RGI->getPolution()==1)
  {
   return true;

  }else
  {
    continue;
  }

}
break;

case 1:
for(zone * RGI :residentialZone->getLocallyAdjacent() )
{


}




break;

};

//commercial


//industrial


