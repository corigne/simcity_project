#include "definitions.hpp"

// update function definitions here

//residential
void residentialGrowth(populated * residentialZone)
{
  int PopCounterResidential = 0;
  int residentialZonePop = residentialZone->getPopulation();
switch(residentialZonePop){

case 0:
for(populated * RGI : residentialZone->getLocallyAdjacent() )
{
  if(RGI->getType()=='T')
  {
  RGI->incPopulation();
  }

}
for(populated * PRGI : residentialZone->getLocallyAdjacent())
{

  if(PRGI->getPopulation()==1)
  {
    PRGI->incPopulation();

  }else
  {
    continue;
  }

}
break;

case 1:
for(populated * PRGI : residentialZone->getLocallyAdjacent())
{

  if(PRGI->getPopulation()==1)
  {
    PopCounterResidential++
  }else
  {
    continue;
  }

if(PopCounterResidential=2)
{
PRGI->incPopulation();
}
}
break;

case 2:

for(populated * PRGI : residentialZone->getLocallyAdjacent())
{

  if(PRGI->getPopulation()==2)
  {
    PopCounterResidential++
  }else
  {
    continue;
  }
  
if(PopCounterResidential=4)
{
PRGI->incPopulation();
}
}


}; //End Switch

//commercial


//industrial


