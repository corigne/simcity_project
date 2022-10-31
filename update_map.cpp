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




break;

};


for(zone * RGI: residentialZone->getLocallyAdjacent() )
      {
         if (*RGI.getPopulation() == 



      }


}

//commercial


//industrial
void IndustiralGrowth(industrial * industryNodeUpdate){
int currentPopulation = industryNodeUpdate->getPopulation();
if(currentPopulation>4)
currentPopulation =4;


switch (currentPopulation){

case 0:
      for(zone* PGI : industryNodeUpdate->getLocallyAdjacent() )

break;

  case 1:


break;

  case 2:

break;

  case 3:

break;

  case 4:

break;

  default:

std::cout<<"Industrial growth update error invalid population retrival"<<std::endl;

break;
};

