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
void popsort_zlist(z_list &m_list)
{
  
}

//sorts populated z_list struct members by Y coord
void ysort_zlist(z_list &m_list)
{

}

void xsort_zlist(z_list &m_list)
{

}