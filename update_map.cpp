#include "definitions.hpp"

// update function definitions here

//residential
void residentialGrowth(residential * residentialZoneUpdate)
{
  int PopCounterResidential = 0;
  
for()


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

