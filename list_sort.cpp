//Author: Nathan Jodoin
//CSCE2110 - SimCity
//Recitation Section 213 - Group 6
//Master List Sorting Functions
#include "definitions.hpp"

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
