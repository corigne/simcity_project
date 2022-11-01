//Salma Omary
//Outputs the map according to population

#include "definitions.hpp"
#include <iostream>

//X Y coordinates initialized to X=0 and Y=0
int y = 0;
int x = 0;


//update after milestone 1 with switch case statements for outputting any possible populated zones
//above update complete 

//in main the parameters will be what fileio returns 

void displayMap(Map * map){

    std::vector<std::vector<zone*> > temp = map->map_grid;
    for(int y = 0; y < map->y_size; y++){
        
        for(int x = 0; x < map->x_size; x++){
            zone* tempZone = temp.at(y).at(x);
            switch(tempZone->getType()){
                case 'R':case 'C':case 'I':{
                    populated* curr = dynamic_cast<populated*>(tempZone);
                    int population = curr->getPopulation();
                    if(population > 0){
                        cout << " " << population << " ";
                    }else{
                        cout << " " << tempZone->getType() << " ";
                    }
                    break;
                }
                default:{
                    cout << " " << tempZone->getType() << " ";
                }
            }
            
            }
            cout << endl;
        }
}
