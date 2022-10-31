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
{


}




break;

};

//commercial


//industrial


<<<<<<< HEAD
=======
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

//paritions given  list by population, returns integer index
int partition(std::vector<populated*> &vec, int low, int high)
{
  int pivot = (low + high)/2;

  //will only stay -1 if there is nothing in the array smaller than the pivot
  int i = low - 1; 
  for(int j = 0; j <= high; j++)
  {
    if(vec[j]->getPopulation() > vec[pivot]->getPopulation())
    {
      i++;
      populated* temp = vec[i];
      vec[i] = vec[j];
      vec[j] = temp;
    }
  }
  //swap lowest index and pivot, return
  populated* temp_low = vec[low];
  vec[low] = vec[i+1];
  vec[i+1] = temp_low;
  
  return i + 1;

}

//sorts populated z_list struct members by population
void quicksort_vec_asc(std::vector<populated*> &vec, int low, int high)
{
  //don't try to sort in a way that will cause an error
  if(low < high)
  {
    //partition
    int piv = partition(vec, low, high);

    //sort high recursive
    quicksort_vec_asc(vec, low, piv - 1);

    //sort low recursive
    quicksort_vec_asc(vec, piv + 1, high);
  }
}

void pop_zone_sort(z_list &lists)
{
  //recursively sort residential, then industrial, then commercial lists
  quicksort_vec_asc(lists.res, 0, lists.res.size()-1);
  
  quicksort_vec_asc(lists.ind, 0, lists.ind.size()-1);

  quicksort_vec_asc(lists.com, 0, lists.com.size()-1);
}
>>>>>>> 5fa49874fd122a0b61be5c5b8e8d1665044b7cc3
