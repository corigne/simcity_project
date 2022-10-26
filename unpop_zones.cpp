//delete after Testing
using namespace std;
#include <vector>
#include<iostream>
class zone {


    public:
    char cellType;
    int power = 0;
    pair<int,int> Location;
    int pollution = 0;
    vector<zone> adjacencyList;
};

///////////////////////////////////////////////////////////////////////


// all the class definitions for unpopulated zones in this file

//road class

//powerline class

//powered_road class

//powerplant class
class powerPlant: public zone{
public:
//change data type

//recursive program to add power to all available cells
void setPoweredState(vector<zone>){
      
            zone * currentCellpower;// 
            power=1;

for(int PsI=0;PsI<8;PsI++){
    zone * nextCellpower = adjacencyList[PsI];

            if(nextCellpower==nullptr||nextCellpower->cellType='R'||nextCellpower==1)
            continue;

        setPoweredState(currentCell.adjacencyList[PsI]);
    };
};
};
};
int main(){



    return 0;
};