#include "definitions.hpp"

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
