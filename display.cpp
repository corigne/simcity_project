//Output of initial region at the beginning of the simulation
//assuming that all zones are unpopulated 

#include "definitions.hpp"
#include <iostream>

//X Y coordinates initialized to X=0 and Y=0
int y = 0;
int x = 0;


//update after milestone 1 with switch case statements for outputting any possible populated zones 

//in main the parameters will be what fileio returns 

void displayMap(Map * map){

    std::vector<std::vector<zone*> > temp = map->map_grid;
    for(int y = 0; y < map->y_size; y++){
        
        for(int x = 0; x < map->x_size; x++){
            zone* tempZone = temp.at(y).at(x);
            cout << " " << tempZone->getType() << " ";
            }
            cout << endl;
        }
    /*
    Current function will be case for if population = 0. 
    Else, {either else if(I or R or C) or switch case} if(currentZone.getType = I or R or C) 
    */
}
