#include "definitions.hpp"

// update function definitions here

//residential EVERY INCPOP NEEDS AN INCWORKER FUNCTION
void residentialGrowth(populated * residentialZone){
  int PopCounterResidential = 0;
  int residentialZonePop = residentialZone->getPopulation();
  if(residentialZonePop>4)
  residentialZonePop=4; 
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
    PopCounterResidential++;
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
    PopCounterResidential++;
  }else
  {
    continue;
  }
  
if(PopCounterResidential=4)
{
PRGI->incPopulation();
}


}
break;

case 3:
for(populated * PRGI : residentialZone->getLocallyAdjacent())
{

  if(PRGI->getPopulation()==3)
  {
    PopCounterResidential++;
  }else
  {
    continue;
  }
  
if(PopCounterResidential=6)
{
PRGI->incPopulation();
}


}
break;
case 4:
for(populated * PRGI : residentialZone->getLocallyAdjacent())
{

  if(PRGI->getPopulation()==4)
  {
    PopCounterResidential++;
  }else
  {
    continue;
  }
  
if(PopCounterResidential=8)
{
PRGI->incPopulation();
}


}
break;

default:
std::cout<<"Failed to correctly get population in Residential."<<std::endl;

}; //End Switch
}
//commercial


void commercialGrowth(commercial * commercialZone){
int commercialZonePop = 0;
commercialZonePop = commercialZone->getPopulation();
if (commercialZonePop >2)
{
commercialZonePop =2;
}
int PopCounterCommercial = 0;

switch(commercialZonePop){

case 0:
for(commercial * CGI : commercialZone->getLocallyAdjacent() )
{
  if(CGI->getType()=='T')
  {
  CGI->incPopulation();
  }

}
for(commercial * CGI : commercialZone->getLocallyAdjacent())
{

  if(CGI->getPopulation()==1)
  {
    CGI->incPopulation();

  }else
  {
    continue;
  }

}
break;

case 1:
for(commercial * PCGI : commercialZone->getLocallyAdjacent())
{

  if(PCGI->getPopulation()==1)
  {
    PopCounterCommercial++;
  }else
  {
    continue;
  }

if(PopCounterCommercial=2)
{
PCGI->incPopulation();
}
}
break;

case 2:
for(commercial * PCGI : commercialZone->getLocallyAdjacent())
{

  if(PCGI->getPopulation()==2)
  {
    PopCounterCommercial++;
  }else
  {
    continue;
  }
  
if(PopCounterCommercial=4)
{
PCGI->incPopulation();
}


}
break;

default:
std::cout<<"Failed to correctly get population in commercial."<<std::endl;

}; //End Switch
}


//industrial


