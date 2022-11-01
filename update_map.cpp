#include "definitions.hpp"
/*
//residential EVERY INCPOP NEEDS AN INCWORKER FUNCTION
void residentialGrowth(populated * residentialZone)
{
  int PopCounterResidential = 0;
  int residentialZonePop = residentialZone->getPopulation();

  if(residentialZonePop>4)
  residentialZonePop=4; 

  switch(residentialZonePop)
  {
    case 0:
    {
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
    }
    case 1:
    {
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
    }

    case 2:
    {
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
    }

    case 3:
    {
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
    }

    case 4:
    {
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
    }

    default:
    {
      std::cout<<"Failed to correctly get population in Residential."<<std::endl;
    }
  } //End Switch
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

<<<<<<< HEAD
void commercialGrowth(commercial * commercialZone){
int commercialZonePop = 0;
commercialZonePop = commercialZone->getPopulation();

if (commercialZonePop >2)
{
commercialZonePop =2;
}
=======
void commercialGrowth(commercial * commercialZone)
{
  int commercialZonePop = 0;
  commercialZonePop = commercialZone->getPopulation();
>>>>>>> f3cd855da083d5ee3a59f6d790868418e734c00b

  if (commercialZonePop >3)
  {
    commercialZonePop =3;
  }

  int PopCounterCommercial = 0;

  switch(commercialZonePop)
  {
    case 0:
    {
      // what do these do?
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

      // what is this for?
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
    }

    case 1:
    { 
      // need comment
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
    }

    case 2:
    {
      //the zone will do nothing
      break;
    }

    default:
    {
    std::cout<<"Failed to correctly get population in commercial."<<std::endl;
    }
  } //End Switch
}
<<<<<<< HEAD
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

if(PopCounterCommercial==1)
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

=======
>>>>>>> f3cd855da083d5ee3a59f6d790868418e734c00b

//industrial
void industrialGrowth(industrial * industrialZone){
  int PopCounterIndustrial = 0;
  int industrialZonePop = 0;
  industrialZonePop =industrialZone->getPopulation();

  if(industrialZonePop>3)
<<<<<<< HEAD
  industrialZonePop=2;
=======
  residentialZonePop=2; 
void industrialGrowth(){



switch(industrialZonePop)
{

>>>>>>> f3cd855da083d5ee3a59f6d790868418e734c00b

switch(industrialZonePop){
case 0:
for(industrial * IGI : industrialZone-> getLocallyAdjacent())
{
  if(IGI->getType()=='T')
  {
      if (checkWorker())
      {
  IGI->incPopulation();
  IGI->addGoods();
  break;
      }
  }

}
<<<<<<< HEAD
for(industrial * IGI : industrialZone->getLocallyAdjacent())
{

  if(IGI->getPopulation()==1)
  {
     if (checkWorker())
     {
    IGI->incPopulation();
    IGI->addGoods();
    break;
     }

  }else
  {
    continue;
  }

}
break;

case 1:
for(industrial * IGI : industrialZone->getLocallyAdjacent())
{

  if(IGI->getPopulation()==1)
  {
    PopCounterIndustrial++;
  }else
  {
    continue;
  }

if(PopCounterIndustrial==1)
{
  if (checkWorker())
  {
IGI->incPopulation();
IGI->addGoods();
break;
  }
}
}
break;

case 2:

break;

default:
std::cout<<"Failed to correctly get industrial population."<<std::endl;
break;


};
}
=======
*/

/////// MERGED by nathan, Please do not overwrite the code below, it is working... //////

//populates provided list struct with res, ind, and comm nodes
void populate_zlist(Map &city_map, z_list &m_list)
{
  for(std::vector<zone*> row : city_map.map_grid)
  {
    for(zone* curr : row)
    {
      switch(curr->getType())
      {
        case 'R':
        {
          residential* temp_r = dynamic_cast<residential*>(curr);
          m_list.res.push_back(temp_r);
          break;
        }
        case 'I':
        {
          industrial* temp_i = dynamic_cast<industrial*>(curr);
          m_list.ind.push_back(temp_i);
          break;
        }
        
        case 'C':
        {
          commercial* temp_c = dynamic_cast<commercial*>(curr);
          m_list.com.push_back(temp_c);
          break;
        }
      }
    }
  }
}

void merge_populated_vectors(std::vector<populated*> &vec, 
  const int low, const int midpoint, const int high)
{
  //created our new halves and midpoint
  std::vector<populated*> left_half, right_half;

  //populate low to mid for left subvec
  for(int i = low; i <= midpoint; i++)
  {
    left_half.push_back(vec[i]);
  }
  // from mid + 1 to the end for right subvec
  for(int i = midpoint+1; i <= high; i++)
  {
    right_half.push_back(vec[i]);
  }

  uint left_i = 0, right_i = 0, merged_i = low;
  
  while(left_i < left_half.size() && right_i < right_half.size())
  {
    //adds the subvector items back in descending order
    if(left_half[left_i]->getPopulation() >= right_half[right_i]->getPopulation())
    {
      vec[merged_i] = left_half[left_i];
      left_i ++;
    }else{
      vec[merged_i] = right_half[right_i];
      right_i ++;
    }
    //iterate merged index
    merged_i ++;
  }

  // copy remaining left + right elements, left priority
  while(left_i < left_half.size())
  {
    vec[merged_i] = left_half[left_i];
    left_i ++;
    merged_i ++;
  }
  while(right_i < right_half.size())
  {
    vec[merged_i] = right_half[right_i];
    right_i ++;
    merged_i ++;
  }
  //to avoid memory bloat in recursion
  left_half.clear();
  right_half.clear();
}

//sorts populated z_list struct members by population
void mergesort_vec_asc(std::vector<populated*> &vec, const int low, const int high)
{
  //base case
  if(low >= high)
  {
    return;
  }
  //this way, if beginning is not 0, we still get a good midpoint
  int midpoint = low + (high - low) / 2;

  //sort recursion begins
  mergesort_vec_asc(vec, low, midpoint);
  mergesort_vec_asc(vec, midpoint+1, high);

  //merge the final results
  merge_populated_vectors(vec, low, midpoint, high);
}

void pop_zone_sort(z_list &lists)
{
  //recursively sort residential, then industrial, then commercial lists
  mergesort_vec_asc(lists.res, 0, lists.res.size()-1);
  
  mergesort_vec_asc(lists.ind, 0, lists.ind.size()-1);

  mergesort_vec_asc(lists.com, 0, lists.com.size()-1);
}
>>>>>>> f3cd855da083d5ee3a59f6d790868418e734c00b
