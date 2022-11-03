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

bool update_map(z_list &list)
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
  }
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

// calculate the adjacent population of a populated* zone
int calc_adj_pop(populated* &zn)
{
  int adj_pop = 0;
  for(zone* adj : zn->getLocallyAdjacent())
  {
    populated* tmp_pop_ptr = dynamic_cast<populated*>(adj);
    if(tmp_pop_ptr != nullptr)
    {
      adj_pop += tmp_pop_ptr->getPopulation();
    }
  }
  return adj_pop;
}

//insertion sort by adjacent population within == local population bubbles
void adj_population_sort(std::vector<populated*> &vec)
{
  for(int i = 1; i < vec.size(); i++)
  {
    //calculate adj population for j
    int adj_pop_i = calc_adj_pop(vec[i]);

    for(int j = i - 1; j > 0; j--)
    {
      //calculate adj population for j
      int adj_pop_j = calc_adj_pop(vec[j]);

      bool same_loc_pop;
      // are the local populations the same?
      same_loc_pop = (vec[i]->getPopulation() == vec[j]->getPopulation());
      // if yes shift larger adj population to the left
      if(same_loc_pop && (adj_pop_i > adj_pop_j))
      {
        populated* temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }
}

//insertion sort by y location within local & adj population == subsets
void y_loc_sort(std::vector<populated*> &vec)
{
  for(int i = 1; i < vec.size(); i++)
  {
    int loc_pop_i = vec[i]->getPopulation();
    int adj_pop_i = calc_adj_pop(vec[i]);
    int y_i = vec[i]->getLocation().second;

    for(int j = i - 1; j > 0; j--)
    {
      int loc_pop_j = vec[j]->getPopulation();
      int adj_pop_j = calc_adj_pop(vec[j]);
      int y_j = vec[j]->getLocation().second;

      bool same_adj_pop, same_loc_pop;
      // are the local and adjacent populations the same?
      same_loc_pop = (loc_pop_i == loc_pop_j);
      same_adj_pop = (adj_pop_i == adj_pop_j);
      // if yes shift larger adj population to the left
      if(same_loc_pop && same_adj_pop && (y_i < y_j))
      {
        populated* temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }
}

//insertion sort by x location within local & adj population & y loc == subsets
void x_loc_sort(std::vector<populated*> &vec)
{
  for(int i = 1; i < vec.size(); i++)
  {
    int loc_pop_i = vec[i]->getPopulation();
    int adj_pop_i = calc_adj_pop(vec[i]);
    int y_i = vec[i]->getLocation().second;
    int x_i = vec[i]->getLocation().first;

    for(int j = i - 1; j > 0; j--)
    {
      int loc_pop_j = vec[j]->getPopulation();
      int adj_pop_j = calc_adj_pop(vec[j]);
      int y_j = vec[j]->getLocation().second;
      int x_j = vec[j]->getLocation().first;

      bool same_adj_pop, same_loc_pop, same_y;
      // are the local and adjacent populations the same?
      same_loc_pop = (loc_pop_i == loc_pop_j);
      same_adj_pop = (adj_pop_i == adj_pop_j);
      same_y = (y_i == y_j);
      // if yes shift larger adj population to the left
      if(same_loc_pop && same_adj_pop && same_y && (x_i < x_j))
      {
        populated* temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }
}

void pop_zone_sort(z_list &lists)
{
  // recursively sort residential, then industrial, then commercial lists
  // population
  mergesort_vec_asc(lists.res, 0, lists.res.size() - 1);
  mergesort_vec_asc(lists.ind, 0, lists.ind.size() - 1);
  mergesort_vec_asc(lists.com, 0, lists.com.size() - 1);

  //resort by adj population within == local population
  adj_population_sort(lists.com);
  adj_population_sort(lists.ind);

  //resort by Y location
  y_loc_sort(lists.com);
  y_loc_sort(lists.ind);

  //resort by X location
  x_loc_sort(lists.com);
  x_loc_sort(lists.ind);

}
