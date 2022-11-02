#include "definitions.hpp"


bool checkWorkerCommercial()
{
    return true;
}
bool checkWorkerIndustrial(industrial * industrialWorkers)
{
  /*
  int workerCount=0;
  for(zone * ICWI: industrialWorkers->getResidentialAdj())
  {
    if(ICWI->hasWorker())
    {
      ICWI->takeWorker();
      workerCount++;
      if(ICWI->hasWorker()&&workerCount<2)
      {ICWI->takeWorker();

      }
    }
  }
  */
return true;
}
// need to be done
bool checkGood()
{
    return true;
}


// residential EVERY INCPOP NEEDS AN INCWORKER FUNCTION
bool residentialGrowth(residential * residentialZone)
{
  int PopCounterResidential = 0;
  int residentialZonePop = residentialZone->getPopulation();

//4 is the largest value that changes the growth rules
  if (residentialZonePop > 4)
    residentialZonePop = 4;

//Input zone population to determine growth rules
  switch (residentialZonePop)
  {
    //population zero
  case 0:
  {
    //case for powerline adjacency
    for (zone *PRGI : residentialZone->getLocallyAdjacent())
    {
      if (PRGI->getType() == 'T')
      {
        residentialZone->incPopulation();
        residentialZone->giveWorker();
        break;
      }
    }
    //case for population adjacency
    for (zone *PRGI : residentialZone->getLocallyAdjacent())
    {

      if (residentialZone->getPopulation() == 1)
      {
        residentialZone->incPopulation();
        residentialZone->giveWorker();
        break;
      }
      else
      {
        continue;
      }
    }

    break;
  }
  case 1:
  {
      //Iterate through each residential zone tracking adjacent zones that meet required population
    for (zone *PRGI : residentialZone->getLocallyAdjacent())
    {
    
      if (residentialZone->getPopulation() == 1)
      {
        PopCounterResidential++;
      }
      else
      {
        continue;
      }

      if (PopCounterResidential == 2)
      {
        residentialZone->incPopulation();
        residentialZone->giveWorker();
        break;
      }
    }
    break;
  }

  case 2:
  {
    for (zone *PRGI : residentialZone->getLocallyAdjacent())
    {

      if (residentialZone->getPopulation() == 2)
      {
        PopCounterResidential++;
      }
      else
      {
        continue;
      }

      if (PopCounterResidential == 4)
      {
        residentialZone->incPopulation();
        residentialZone->giveWorker();
        break;
      }
    }
    break;
  }

  case 3:
  {
    for (zone *PRGI : residentialZone->getLocallyAdjacent())
    {

      if (residentialZone->getPopulation() == 3)
      {
        PopCounterResidential++;
      }
      else
      {
        continue;
      }

      if (PopCounterResidential == 6)
      {
        residentialZone->incPopulation();
        residentialZone->giveWorker();
        break;
      }
    }
    break;
  }

  case 4:
  {
    for (zone *PRGI : residentialZone->getLocallyAdjacent())
    {

      if (residentialZone->getPopulation() == 4)
      {
        PopCounterResidential++;
      }
      else
      {
        continue;
      }

      if (PopCounterResidential == 8)
      {
        residentialZone->incPopulation();
        residentialZone->giveWorker();
        break;
      }
    }
    break;
  }

  default:
  {
    std::cout << "Failed to correctly get population in Residential." << std::endl;
  }
  }; // End Switch
}
// commercial
bool commercialGrowth(commercial *commercialZone)
{
  int commercialZonePop = 0;
  commercialZonePop = commercialZone->getPopulation();

  if (commercialZonePop > 3)
  {
    commercialZonePop = 3;
  }

  int PopCounterCommercial = 0;

  switch (commercialZonePop)
  {
  case 0:
  {

    for (zone *CGI : commercialZone->getLocallyAdjacent())
    {
      if (commercialZone->getType() == 'T')
      {
        if (checkWorkerCommercial() && checkGood())
        {
          commercialZone->incPopulation();
          break;
        }
      }
    }

    for (zone *CGI : commercialZone->getLocallyAdjacent())
    {

      if (commercialZone->getPopulation() == 1)
      {
        if (checkWorkerCommercial() && checkGood())
        {
          commercialZone->incPopulation();
          break;
        }
      }
      else
      {
        continue;
      }
    }
    break;
  }

  case 1:
  {
    // need comment
    for (zone *PCGI : commercialZone->getLocallyAdjacent())
    {

      if (commercialZone->getPopulation() == 1)
      {
        PopCounterCommercial++;
      }
      else
      {
        continue;
      }

      if (PopCounterCommercial == 1)
      {
        if (checkWorkerCommercial() && checkGood())
        {
          commercialZone->incPopulation();
          break;
        }
      }
    }
    break;
  }

  case 2:
  {
    // the zone will do nothing
    break;
  }

  default:
  {
    std::cout << "Failed to correctly get population in commercial." << std::endl;
  }
  break;
  }; // End Switch
}
// industrial
bool industrialGrowth(industrial *industrialZone)
{
  int PopCounterIndustrial = 0;
  int industrialZonePop = 0;
  industrialZonePop = industrialZone->getPopulation();

  if (industrialZonePop > 3)
    industrialZonePop = 2;

  switch (industrialZonePop)
  {
  case 0:
    for (zone *IGI : industrialZone->getLocallyAdjacent())
    {
      if (IGI->getType() == 'T')
      {
        if (checkWorkerIndustrial(industrialZone))
        {
          industrialZone->incPopulation();
          industrialZone->addGoods();
          return true;
          break;
        }
      }
    }
  case 1:
    for (zone *PIGI : industrialZone->getLocallyAdjacent())
    {
      if (industrialZone->getPopulation() == 1)
        PopCounterIndustrial++;

      // Adjacent zones meet population requirement for industrial growth
      if (PopCounterIndustrial == 2)
      {
        if (checkWorkerIndustrial(industrialZone))
        {
          industrialZone->incPopulation();
          industrialZone->addGoods();
          return true;
          // If there are no available workers end the loop
        }
        else
        {
          return false;
        }
      }else
      {
        return false;
      }
    }

  case 2:

    for (zone *PIGI : industrialZone->getLocallyAdjacent())
    {
      if (industrialZone->getPopulation() == 2)
      {
        PopCounterIndustrial++;
      }
      if (PopCounterIndustrial == 4)
      if(checkWorkerIndustrial(industrialZone))
      {
      {
        industrialZone->incPopulation();
        industrialZone->addGoods();
        break;
      }
      }else{break;}
    }
    break;

  default:
    std::cout << "Failed to correctlly get population for industrial zone." << std::endl;
    break;
  }; // end switch
}

bool update_map(z_list &list)
  {
bool changed = false;
//for list of residential residentialGrowth()
for(populated* curr : list.res)
    {
      residential* temp_res = dynamic_cast<residential*>(curr);
      if(residentialGrowth(temp_res)==true)
      {changed=true}
    }
//for list of commercial commercialGrowth()
for(populated* curr : list.com)
    {
      commercial* temp_com = dynamic_cast<commercial*>(curr);
      commercialGrowth(temp_com);
    }

//for list of industrail industrialGrowth()
for(populated* curr : list.ind)
    {
      industrial* temp_ind = dynamic_cast<industrial*>(curr);
      C=C+industrialGrowth(temp_ind);
    }
    if(C>=1)
    changed=true;
  return changed;
  }

/////// MERGED by nathan, Please do not overwrite the code below, it is working... //////
// populates provided list struct with res, ind, and comm nodes
void populate_zlist(Map &city_map, z_list &m_list)
{
  for (std::vector<zone *> row : city_map.map_grid)
  {
    for (zone *curr : row)
    {
      switch (curr->getType())
      {
      case 'R':
      {
        residential *temp_r = dynamic_cast<residential *>(curr);
        m_list.res.push_back(temp_r);
        break;
      }
      case 'I':
      {
        industrial *temp_i = dynamic_cast<industrial *>(curr);
        m_list.ind.push_back(temp_i);
        break;
      }

      case 'C':
      {
        commercial *temp_c = dynamic_cast<commercial *>(curr);
        m_list.com.push_back(temp_c);
        break;
      }
      };
    }
  }
}

void merge_populated_vectors(std::vector<populated *> &vec,
                             const int low, const int midpoint, const int high)
{
  // created our new halves and midpoint
  std::vector<populated *> left_half, right_half;

  // populate low to mid for left subvec
  for (int i = low; i <= midpoint; i++)
  {
    left_half.push_back(vec[i]);
  }
  // from mid + 1 to the end for right subvec
  for (int i = midpoint + 1; i <= high; i++)
  {
    right_half.push_back(vec[i]);
  }

  int left_i = 0, right_i = 0, merged_i = low;

  while (left_i < left_half.size() && right_i < right_half.size())
  {
    // adds the subvector items back in descending order
    if (left_half[left_i]->getPopulation() >= right_half[right_i]->getPopulation())
    {
      vec[merged_i] = left_half[left_i];
      left_i++;
    }
    else
    {
      vec[merged_i] = right_half[right_i];
      right_i++;
    }
    // iterate merged index
    merged_i++;
  }

  // copy remaining left + right elements, left priority
  while (left_i < left_half.size())
  {
    vec[merged_i] = left_half[left_i];
    left_i++;
    merged_i++;
  }
  while (right_i < right_half.size())
  {
    vec[merged_i] = right_half[right_i];
    right_i++;
    merged_i++;
  }
  // to avoid memory bloat in recursion
  left_half.clear();
  right_half.clear();
}

// sorts populated z_list struct members by population
void mergesort_vec_asc(std::vector<populated *> &vec, const int low, const int high)
{
  // base case
  if (low >= high)
  {
    return;
  }
  // this way, if beginning is not 0, we still get a good midpoint
  int midpoint = low + (high - low) / 2;

  // sort recursion begins
  mergesort_vec_asc(vec, low, midpoint);
  mergesort_vec_asc(vec, midpoint + 1, high);

  // merge the final results
  merge_populated_vectors(vec, low, midpoint, high);
}

void pop_zone_sort(z_list &lists)
{
  // recursively sort residential, then industrial, then commercial lists
  mergesort_vec_asc(lists.res, 0, lists.res.size() - 1);

  mergesort_vec_asc(lists.ind, 0, lists.ind.size() - 1);

  mergesort_vec_asc(lists.com, 0, lists.com.size() - 1);
}
