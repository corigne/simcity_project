#include "definitions.hpp"


// residential EVERY INCPOP NEEDS AN INCWORKER FUNCTION
bool residentialGrowth(residential * residentialZone)
{
  int PopCounterResidential = 0;
  int residentialZonePop = residentialZone->getPopulation();

//4 is the largest value that changes the growth rules
  if (residentialZonePop > 4)
  {
    residentialZonePop = 4;
  }

//Input zone population to determine growth rules
  switch (residentialZonePop)
  {
    //population zero
    case 0:
    {
      //case for powerline adjacency
      for (zone *PRGI : residentialZone->getLocallyAdjacent())
      {
        if (PRGI != nullptr && PRGI->getType() == 'T')
        {
          residentialZone->giveWorker();
          return true;
        }
      }
      //case for population adjacency
      for (zone *PRGI : residentialZone->getLocallyAdjacent())
      {
        //check OOB condition
        if(PRGI != nullptr)
        {
          //need to check if the locally adjacent zones are populated types
          switch(PRGI->getType())
          {
            case 'R': case 'I': case 'C':
            {
              populated* temp_pop = dynamic_cast<populated*>(PRGI);
              if (temp_pop->getPopulation() >= 1)
              {
                residentialZone->giveWorker();
                return true;
              }
              else
              {
                continue;
              }
            }
          }
        }
      }
      return false;
    }

    case 1:
    {
        //Iterate through each residential zone tracking adjacent zones that meet required population
      for (zone *PRGI : residentialZone->getLocallyAdjacent())
      {
        //check for OOB condition
        if(PRGI != nullptr)
        {  
          //check if populated type zone
          switch(PRGI->getType())
          {
            case 'R': case 'I': case 'C':
            {
              //dynamic casting required here to check population
              populated* temp_pop = dynamic_cast<populated*>(PRGI);
              if (temp_pop->getPopulation() >= 1)
              {
                PopCounterResidential++;
              }
              else
              {
                continue;
              }

              if (PopCounterResidential == 2)
              {
                residentialZone->giveWorker();
                return true;
              }
            }
          }
        }  
      }
      return false;
    }

    case 2:
    {
        //Iterate through each residential zone tracking adjacent zones that meet required population
      for (zone *PRGI : residentialZone->getLocallyAdjacent())
      {
        //check for OOB condition
        if(PRGI != nullptr)
        {  
          //check if populated type zone
          switch(PRGI->getType())
          {
            case 'R': case 'I': case 'C':
            {
              //dynamic casting required here to check population
              populated* temp_pop = dynamic_cast<populated*>(PRGI);
              if (temp_pop->getPopulation() >= 2)
              {
                PopCounterResidential++;
              }
              else
              {
                continue;
              }

              if (PopCounterResidential == 4)
              {
                residentialZone->giveWorker();
                return true;
              }
            }
          }
        }  
      }
      return false;
    }

    case 3:
    {
        //Iterate through each residential zone tracking adjacent zones that meet required population
      for (zone *PRGI : residentialZone->getLocallyAdjacent())
      {
        //check for OOB condition
        if(PRGI != nullptr)
        {  
          //check if populated type zone
          switch(PRGI->getType())
          {
            case 'R': case 'I': case 'C':
            {
              //dynamic casting required here to check population
              populated* temp_pop = dynamic_cast<populated*>(PRGI);
              if (temp_pop->getPopulation() >= 3)
              {
                PopCounterResidential++;
              }
              else
              {
                continue;
              }

              if (PopCounterResidential == 6)
              {
                residentialZone->giveWorker();
                return true;
              }
            }
          }
        }  
      }
      return false;
    }

    case 4:
    {
        //Iterate through each residential zone tracking adjacent zones that meet required population
      for (zone *PRGI : residentialZone->getLocallyAdjacent())
      {
        //check for OOB condition
        if(PRGI != nullptr)
        {  
          //check if populated type zone
          switch(PRGI->getType())
          {
            case 'R': case 'I': case 'C':
            {  
              //dynamic casting required here to check population
              populated* temp_pop = dynamic_cast<populated*>(PRGI);
              if (temp_pop->getPopulation() >= 4)
              {
                PopCounterResidential++;
              }
              else
              {
                continue;
              }

              if (PopCounterResidential == 8)
              {
                residentialZone->giveWorker();
                return true;
              }
            }  
          }
        }  
      }
      return false;
    }

    default:
    {
      std::cout << "Failed to correctly get population in Residential." << std::endl;
      return false;
    }
  }; // End Switch
}
// commercial
bool commercialGrowth(commercial *commercialZone)
{
  bool update = false;
  int commercialZonePop = 0;
  int PopCounterCommercial = 0;
  commercialZonePop = commercialZone->getPopulation();

  if (commercialZonePop > 1)
  {
    commercialZonePop = 1;
  }

  switch (commercialZonePop)
  {
    case 0:
    {
      //check for workers && goods, using appropriate data members

      for (zone *CGI : commercialZone->getLocallyAdjacent())
      {
        if(CGI != nullptr)
        {
          //case where adj to powerline
          if (CGI->getType() == 'T')
          {
            update = true;
            break;
          }

          //nearby zone population >=1
          switch(CGI->getType())
          {
            case 'R': case 'I': case 'C':
            {
              populated* temp_pop = dynamic_cast<populated*>(CGI);
              if(temp_pop->getPopulation() >= 1)
              {
                update = true;
                break;
              }
            }
          }
          if(update == true)
          {
            break;
          }
        }
      }

      //if cell has suff condition to update
      if(update)
      {
        //check for goods + workers
        for(residential* curr_res : commercialZone->getResidentialAdj())
        {
          //check for worker
          if(curr_res->hasWorker())
          {
            //check for goods
            for(industrial* curr_ind : commercialZone->getIndustrialAdj())
            {
              if(curr_ind->hasGoods())
              {
                //only if both worker and goods are available
                curr_res->takeWorker();
                curr_ind->sendGoods();
                return true;
              }
            }
          }
        }
      }
      return false;
    }// case 0 end
  
    case 1:
    {
      // need comment
      for (zone *PCGI : commercialZone->getLocallyAdjacent())
      {
        if(PCGI != nullptr)
        {
          switch(PCGI->getType())
          {
            case 'R': case 'I': case 'C':
            {
              populated* temp_pop = dynamic_cast<populated*>(PCGI);
              if (temp_pop->getPopulation() >= 1)
              {
                PopCounterCommercial++;
              }
              else
              {
                continue;
              }

              if (PopCounterCommercial == 2)
              {
                update = true;
                break;
              }
            }
          }
        }
      }

      if(update)
      {
        //check for goods + workers
        for(residential* curr_res : commercialZone->getResidentialAdj())
        {
          //check for worker
          if(curr_res->hasWorker())
          {
            //check for goods
            for(industrial* curr_ind : commercialZone->getIndustrialAdj())
            {
              if(curr_ind->hasGoods())
              {
                //only if both worker and goods are available
                curr_res->takeWorker();
                curr_ind->sendGoods();
                return true;
              }
            }
          }
        }
      }
      return false;
    }

    default:
    {
      std::cout << "Failed to correctly get population in commercial." << std::endl;
      return false;
    }
  }; // End Switch
}
// industrial
bool industrialGrowth(industrial *industrialZone)
{
  bool update = false;
  int PopCounterIndustrial = 0;
  std::pair<bool, residential*> worker1;

  //this zone's population
  int industrialZonePop = 0;
  industrialZonePop = industrialZone->getPopulation();

  if (industrialZonePop > 3)
  {
    industrialZonePop = 2;
  }

  switch (industrialZonePop)
  {
    case 0:
    {

      for (zone *IGI : industrialZone->getLocallyAdjacent())
      {
        if (IGI != nullptr)
        {
          //check for adj powerline
          if (IGI->getType() == 'T')
          {
            update = true;
            break;
          }
          //if not cheak for adj pop >=1
          switch(IGI->getType())
          {
            case 'R': case 'I': case 'C':
            {
              populated* temp_pop = dynamic_cast<populated*>(IGI);
              //check population
              if(temp_pop->getPopulation()>=1)
              {
                update = true;
                break;
              }
            }
          }
        }  
      }
      
      //sufficient case conditions have been met if true
      if(update)
      {
        for(residential* curr_r : industrialZone->getResidentialAdj())
        {
          if(curr_r->hasWorker())
          {
            //1st avaiable workers!
            if(!(worker1.first == true))
            {
              worker1.first = true;
              worker1.second = curr_r;

            }
            else //2nd available worker
            {
              worker1.second->takeWorker();
              curr_r->takeWorker();
              return true;
            }
          }
        }
      }
      return false;
    }

    case 1:
    {
      //check for at least 2 locally adj zones with population of 1 or higher
      for (zone *PIGI : industrialZone->getLocallyAdjacent())
      {
        if(PIGI != nullptr)
        {
          switch(PIGI->getType())
          {
            //if adj zone is populated
            case 'R': case 'I': case 'C':
            {
              //dynamicaly cast to a pop*
              populated * temp_pop;
              temp_pop = dynamic_cast<populated*>(PIGI);
              
              //and check population
              if(temp_pop->getPopulation() >= 1)
              {
                PopCounterIndustrial += 1;
              }

              //sufficient condition for update
              if(PopCounterIndustrial == 2)
              {
                update = true;
                break;
              }
            }
          }
        }
      }

      //sufficient case conditions have been met if true
      if(update)
      {
        //check for 2 workers available in residential adjacency list
        for(residential* curr_r : industrialZone->getResidentialAdj())
        {
          if(curr_r->hasWorker())
          {
            //1st avaiable workers!
            if(!(worker1.first == true))
            {
              worker1.first = true;
              worker1.second = curr_r;

            }
            else //2nd available worker
            {
              worker1.second->takeWorker();
              curr_r->takeWorker();
              return true;
            }
          }
        }
      }
      
      return false;
    }
    
    case 2:
    {
      //check for at least 4 locally adj zones with population of 2 or higher
      for (zone *PIGI : industrialZone->getLocallyAdjacent())
      {
        if(PIGI != nullptr)
        {
          switch(PIGI->getType())
          {
            //if adj zone is populated
            case 'R': case 'I': case 'C':
            {
              //dynamicaly cast to a pop*
              populated * temp_pop;
              temp_pop = dynamic_cast<populated*>(PIGI);
              
              //and check population
              if(temp_pop->getPopulation() >= 2)
              {
                PopCounterIndustrial += 1;
              }

              //sufficient condition for update
              if(PopCounterIndustrial == 4)
              {
                update = true;
                break;
              }
            }
          }
        }
      }

      //sufficient case conditions have been met if true
      if(update)
      {
        //check for 2 workers available in residential adjacency list
        for(residential* curr_r : industrialZone->getResidentialAdj())
        {
          if(curr_r->hasWorker())
          {
            //1st avaiable workers!
            if(!(worker1.first == true))
            {
              worker1.first = true;
              worker1.second = curr_r;

            }
            else //2nd available worker
            {
              worker1.second->takeWorker();
              curr_r->takeWorker();
              return true;
            }
          }
        }
      }

      return false;
    }

    default:
    {
      std::cout << "Failed to correctlly get population for industrial zone." << std::endl;
      return false;
    }
  }; // end switch
}

// main update function
bool updateMap(z_list &list)
{ 
  bool changed = false;
  //populate growing and inc at the end to avoid ripple growth
  std::vector<populated*> growing;
  //for list of commercial commercialGrowth()
  for(populated* curr : list.com)
  {
    commercial* temp_com = dynamic_cast<commercial*>(curr);
    if(commercialGrowth(temp_com)==true)
    {
      growing.push_back(curr);
      changed = true;
    }
  }

  //for list of industrail industrialGrowth()
  for(populated* curr : list.ind)
  {
    industrial* temp_ind = dynamic_cast<industrial*>(curr);
    if(industrialGrowth(temp_ind)==true)
    {
      growing.push_back(curr);
      changed = true;
    }
  }

  //for list of residential residentialGrowth()
  for(populated* curr : list.res)
  {
    residential* temp_res = dynamic_cast<residential*>(curr);
    if(residentialGrowth(temp_res)==true)
    {
      growing.push_back(curr);
      changed=true;
    }
  }

  //update all populations at once to avoid ripple effect
  for(populated* each : growing)
  {
    each->incPopulation();
    if(each->getType() == 'I')
    {
      industrial* temp_i = dynamic_cast<industrial*>(each);
      temp_i->addGoods();
    }
  }
  return changed;
}