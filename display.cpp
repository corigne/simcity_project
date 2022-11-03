//Salma Omary
//Outputs the map according to population

#include "definitions.hpp"


//update after milestone 1 with switch case statements for outputting any possible populated zones
//above update complete 

void displayMap(Map * map, int x_1, int y_1, int x_2, int y_2)
{
    //X Y coordinates initialized to X=0 and Y=0
    std::vector<std::vector<zone*> > temp = map->map_grid;
    for(int y = y_1; y <= y_2; y++)
    {
        
        for(int x = x_1; x <= x_2; x++){
            zone* tempZone = temp.at(y).at(x);
            switch(tempZone->getType()){
                case 'R':case 'C':case 'I':
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
                default:
                {
                    std::cout << " " << tempZone->getType() << " ";
                }
            }
            
        }
        std::cout << std::endl;
    }
}

void displayPollutedMap(Map * map, int x_1, int y_1, int x_2, int y_2)//function same as above but displays pollution
{
    std::cout << std::endl;
     std::cout << "POLLUTION MAP: "<< std::endl;
    //X Y coordinates initialized to X=0 and Y=0
    std::vector<std::vector<zone*> > temp = map->map_grid;
    for(int y = y_1; y <= y_2; y++)
    {
        
        for(int x = x_1; x <= x_2; x++){
            zone* tempZone = temp.at(y).at(x);
            int pollution = tempZone->getPollution();
            std::cout << " " << pollution << " ";
        }
    std::cout << std::endl;
    }
    std::cout << std::endl;
}
