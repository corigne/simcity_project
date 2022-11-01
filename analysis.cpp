//started working on trevonne code at 9:25 Oct 31

#include "definitions.hpp"
using namespace std;

void analysis(Map finalmap, z_list list) //edit  here, changed from map to Map, z_lists to z_list
{
    char selection;
    int respop = 0;
    int compop = 0;
    int indpop = 0;
    int totalpol = 0;
    int row, col, endrow, endcol;//edit here, fixed variable names

    for(int i = 0; i < list.res.size(); i++)
    {
        respop += list.res[i];
    }

    for(int i = 0; i < list.com.size(); i++)
    {
        compop += list.com[i];
    }

    for(int i = 0; i < list.ind.size(); i++)
    {
        indpop += list.ind[i];
    }

    for(std::vector<zone*> row : finalmap.map_grid)
    {
        for(zone* curr : row)
        {
            totalpol += curr->getPolution(); //edit here changed spelling bc this is how it was spelled in zone.cpp
        }
    }

    cout << "Total Residential Population: " << respop << endl;
    cout << "Total Industrial Workers: " << indpop << endl;
    cout << "Total Commercial Workers: " << compop << endl;
    cout << "Total Regional Pollution: " << totalpol << endl;

    cout << "Would you like to specify an area to analyze? (y for yes, n for no) : ";
    cin >> selection;

    respop = 0;
    indpop = 0;
    compop = 0;
    totalpol = 0;

    while(selection == 'y')
    {
        cout << "Please enter a starting row: ";
        cin >> row;
        cout << "Please enter a starting column: ";
        cin >> col;
        cout << "Please enter a ending row: ";
        cin >> endrow;
        cout << "Please enter a ending column: ";
        cin >> endcol;

        if(row < 0 || col < 0 || endrow > finalmap.map_grid.size() || endcol > finalmap.map_grid.at(endrow).size())
        {
            cout << "The coordinates you have entered are invalid." << endl; //edit here typo
        }
        else
        {
            for(int i = row; i <= endrow; i++)
            {
                for(int j = col; i <= endcol; j++)
                {
                    totalpol += finalmap.map_grid[i][j].getPollution();
                }
            }
        }

        cout << "Would you like to specify another area to analyze? (y for yes, n for no) : ";
        cin >> selection;
    }
        
}
