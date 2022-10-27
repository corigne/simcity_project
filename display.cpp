//Output of initial region at the beginning of the simulation
//assuming that all zones are unpopulated 

#include "definitions.hpp"
#include <iostream>
using namespace std;

//X Y coordinates initialized to X=0 and Y=0
int y = 0;
int x = 0;


//update after milestone 1 with switch case statements for outputting any possible populated zones 


void displayMap(Map * map){

    vector<vector<zone*> > temp = map->map_grid;
    for(int y = 0; y < map->y_size; y++){
        
        for(int x = 0; x < map->x_size; x++){
            zone* tempZone = temp.at(y).at(x);
            cout << " " << tempZone->getType() << " ";
            }
        }
}