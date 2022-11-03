//started working on trevonne code at 9:25 Oct 31

#include "definitions.hpp"
// using namespace std;

void analysis(Map * finalmap, z_list list) //edit  here, changed from map to Map * (Map pointer), z_lists to z_list
{
    // displayMap(finalmap);
    char selection;
    int respop = 0;
    int compop = 0;
    int indpop = 0;
    int totalpol = 0;
    int row, col, endrow, endcol;//edit here, fixed variable names

    for(int i = 0; i < list.res.size(); i++)
    {
        respop += list.res.at(i)->getPopulation(); //edit here fixed syntax
    }

    for(int i = 0; i < list.com.size(); i++)
    {
        compop += list.com.at(i)->getPopulation(); //edit here fixed syntax
    }

    for(int i = 0; i < list.ind.size(); i++)
    {
        indpop += list.ind.at(i)->getPopulation(); //edit here fixed syntax
    }

    for(std::vector<zone*> row : finalmap->map_grid)
    {
        for(zone* curr : row)
        {
            totalpol += curr->getPollution(); 
        }
    }

    std::cout << "Total Residential Population: " << respop << std::endl;
    std::cout << "Total Industrial Workers: " << indpop << std::endl;
    std::cout << "Total Commercial Workers: " << compop << std::endl;
    std::cout << "Total Regional Pollution: " << totalpol << std::endl;

    std::cout << "Would you like to specify an area to analyze? (y for yes, n for no) : ";
    std::cin >> selection;

    respop = 0;
    indpop = 0;
    compop = 0;
    totalpol = 0;

    while(selection == 'y')
    {
        std::cout << "Please enter a starting column (X): ";
        std::cin >> col;
        std::cout << "Please enter a starting row (Y): ";
        std::cin >> row;
        std::cout << "Please enter a ending column (X): ";
        std::cin >> endcol;
        std::cout << "Please enter a ending row (Y): ";
        std::cin >> endrow;
        

        if(row < 0 || col < 0 || endrow > finalmap->map_grid.size() || endcol > finalmap->map_grid.at(endrow).size())
        {
            std::cout << "The coordinates you have entered are invalid." << std::endl; //edit here typo
            std::cout << "Would you like to specify another area to analyze? (y for yes, n for no) : ";
            std::cin >> selection;
        }
        else
        {
            std:: cout << "DISPLAY POP MAP FROM (X:" << col << ", Y:" << row << ") TO (" << endcol << ", " << endrow <<")" << std::endl;
            std::vector<std::vector<zone*> > temp = finalmap->map_grid;
            for(int y = row; y <= endrow; y++)
            {
                // cout << "ROW " << y << ":"<< endl;
                for(int x = col; x <= endcol; x++)
                {
                    zone* tempZone = temp.at(y).at(x);
                    populated* curr = dynamic_cast<populated*>(tempZone); /*edit here:
                    dynamically cast a populated pointer to be equal to the zone to access population of that zone*/
                    totalpol += tempZone->getPollution(); 
                    switch(tempZone->getType())
                    {
                        case 'R':
                            respop += curr->getPopulation();//edit here fixed syntax
                            break;
                        case 'C':
                            compop += curr->getPopulation();// edit here fixed syntax                            
                            break;
                        case 'I':
                            indpop += curr->getPopulation();// edit here fixed syntax            
                            break;
                    }
                    
                }
                
        }
        displayMap(finalmap, col, row, endcol, endrow);
        displayPollutedMap(finalmap, col, row, endcol, endrow);

        std::cout << "Total residential population in this region: " << respop << std::endl;//edit here added output statement
        std::cout << "Total commercial population in this region: " << compop << std::endl; //edit here added output statement
        std::cout << "Total Industrial population in this region: " << indpop << std::endl; //edit here added output statement
        std::cout << "Total pollution in this region: " << totalpol << std::endl;

        std::cout << "Would you like to specify another area to analyze? (y for yes, n for no) : ";
        std::cin >> selection;
    }
        
}
}
