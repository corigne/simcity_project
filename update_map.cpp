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
for(residential * PRGI : residentialZone->getLocallyAdjacent() )
{
  if(PRGI->getType()=='T')
  {
       PRGI->incPopulation();
    PRGI->giveWorker();
    break;
  }
}
for(residential * PRGI : residentialZone->getLocallyAdjacent())
{

  if(PRGI->getPopulation()==1)
  {
    PRGI->incPopulation();
    PRGI->giveWorker();
    break;
  }else
  {
    continue;
  }

}

break;

case 1:
for(residential * PRGI : residentialZone->getLocallyAdjacent())
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
PRGI->giveWorker();
break;
}
}
break;

case 2:
for(residential * PRGI : residentialZone->getLocallyAdjacent())
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
    PRGI->giveWorker();
    break;
}


}
break;

case 3:
for(residential * PRGI : residentialZone->getLocallyAdjacent())
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
    PRGI->giveWorker();
    break;
}


}
break;
case 4:
for(residential * PRGI : residentialZone->getLocallyAdjacent())
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
    PRGI->giveWorker();
    break;
}


}
break;

default:
std::cout<<"Failed to correctly get population in Residential."<<std::endl;

}; //End Switch
}
//commercial

bool checkWorker(){
if(true)
return true;
}

bool checkGood(){
  if(true)
  return true;
}

void commercialGrowth(commercial * commercialZone){
int commercialZonePop = 0;
commercialZonePop = commercialZone->getPopulation();

if (commercialZonePop >3)
{
commercialZonePop =3;
}

int PopCounterCommercial = 0;

switch(commercialZonePop){

case 0:
for(commercial * CGI : commercialZone->getLocallyAdjacent() )
{
  if(CGI->getType()=='T')
  {
      if (checkWorker()&&checkGood())
      {
  CGI->incPopulation();
  break;
      }
  }

}
for(commercial * CGI : commercialZone->getLocallyAdjacent())
{

  if(CGI->getPopulation()==1)
  {
     if (checkWorker()&&checkGood())
     {
    CGI->incPopulation();
    break;
     }

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

if(PopCounterCommercial=1)
{
  if (checkWorker()&&checkGood())
  {
PCGI->incPopulation();
break;
  }
}
}
break;

case 2:
//the zone will do nothing
break;

default:
std::cout<<"Failed to correctly get population in commercial."<<std::endl;

}; //End Switch
}


//industrial
void industrialGrowth(industrial * industrialZone){
  int PopCounterIndustrial = 0;
  int industrialZonePop = 0;
  industrialZonePop =industrialZone->getPopulation();

  if(industrialZonePop>3)
  industrialZonePop=2;

switch(industrialZonePop){
case 0:

break;

case 1:

break;

case 2:

break;

default:
std::cout<<"Failed to correctly get industrial population."<<std::endl;
break;


};
}
