#include "definitions.hpp"

// update function definitions here

//residential


//commercial


//industrial


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

//sorts populated z_list struct members by population
void popsort_zl(z_list &m_list, int low, int high)
{
  
}

//paritions given populated* list by population, given (size/2)-1 pivot
void pop_part(std::vector<populated*> list)
{

}

//sorts populated z_list struct members by Y coord
void ysort_zl(z_list &m_list)
{

}

void xsort_zl(z_list &m_list)
{

}

//returns an ideal pivot for quicksort given 3 integers
int median_of_3(int a, int b, int c)
{
  if((a >= b && a <= c)||(a >= c && a <= b)){return a;}
  if((b >= a && b <= c)||(b >= c && b <= a)){return b;}
  if((c >= a && c <= b)||(c >= b && c <= a)){return c;}
  //in case of failure?
  return b;
}
  