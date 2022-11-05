//Salma Omary
//Outputs the map according to population, also outputs a map based on the pollution in the zone

#include "definitions.hpp"



void displayMap(Map * map, int x_1, int y_1, int x_2, int y_2)
{
    std::vector<std::vector<zone*> > temp = map->map_grid;//initializes temp variable representing zones
    for(int y = y_1; y <= y_2; y++)//iterates through the map, top to bottom
    {
        for(int x = x_1; x <= x_2; x++){//nested for loop that iterates through the map, left to right
            zone* tempZone = temp.at(y).at(x);
            switch(tempZone->getType()){
                case 'R':case 'C':case 'I'://will output population number rather than zone type for populated zones > 0
                {
                    populated* curr = dynamic_cast<populated*>(tempZone);
                    int population = curr->getPopulation();
                    if(population > 0){
                        std::cout << " " << population << " ";
                    }else{
                        std::cout << " " << tempZone->getType() << " ";
                    }
                    break;
                }
                default://outputs zone type for non-populated zones
                {
                    std::cout << " " << tempZone->getType() << " ";
                }
            }
            
        }
        std::cout << std::endl;
    }
}

void displayPollutedMap(Map * map, int x_1, int y_1, int x_2, int y_2)//displays a pollution map
{
    std::cout << std::endl;
    std::cout << "POLLUTION MAP: "<< std::endl;
    std::vector<std::vector<zone*> > temp = map->map_grid;
    for(int y = y_1; y <= y_2; y++)
    {
        
        for(int x = x_1; x <= x_2; x++){//iterates top left to right and outputs pollution in that zone (including if = 0)
            zone* tempZone = temp.at(y).at(x);
            int pollution = tempZone->getPollution();
            std::cout << " " << pollution << " ";
        }
    std::cout << std::endl;
    }
    std::cout << std::endl;
}
