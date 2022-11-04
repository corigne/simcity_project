//Trevonne 
//takes file and parses into dthe different data sections, uses the file name within the first file to open and parse a file containing the initial map state

#include "definitions.hpp"
//void function that takes in refernce pointers for integers and a 2d vector, and a string for the configuration file name
void fileio(std::string config, int &time, int &refresh, std::vector<std::vector<zone*> > &map)
{
	std::ifstream  in_f; 
	std::vector<std::string> data;
	std::vector<std::vector<char> > city;
	std::string line, temp, filename;
	int position;
	int row = 0;

	//opening the configuration file and checks if file is opened
	in_f.open(config);

	if(!in_f.is_open())
	{
   		std::cout<<"Can't open the file";
	}
	// reads in file and stores strings after :. This includes the time, the refresh rate, and the region file name
	while(getline(in_f,line))
	{
		position = line.find(":");
		temp = line.substr(position + 1);
		data.push_back(temp);

		temp = "";
	}
	in_f.close();
	//sets variables to data within file
	filename = data[0];
	time = stoi(data[1]);
	refresh = stoi(data[2]);
	//open region file
	in_f.open(filename);
	//read in region file and parses it into a 2d vector of characters
	while(getline(in_f,line))
	{
		std::vector<char> temp1;
		city.push_back(temp1);
		for(int i = 0; i < line.length(); i++)
		{
			if(line[i] != ',')
			{
				city.at(row).push_back(line[i]);
			}
		}
		row++;
	}

	in_f.close();

	int x, y;
	//used the 2d character vector to populate a 2d object vector with the region types
// Y LOOP
	for(int i = 0; i < city.size(); i++)
	{
			std::vector<zone*> temp2;
			//X LOOP
			for(int j = 0; j < city[i].size(); j++)
			{
				y = i;
				x = j;
				if(city[i][j] == ' ')
				{
					temp2.push_back(new zone(x, y));
				}
				if(city[i][j] == 'I')
				{
					temp2.push_back(new industrial(x, y));
				}
				if(city[i][j] == 'R')
				{
					temp2.push_back(new residential(x, y));
				}
				if(city[i][j] == 'C')
				{
					temp2.push_back(new commercial(x, y));
				}
				if(city[i][j] == 'T')
				{
					temp2.push_back(new powerline(x, y));
				}
				if(city[i][j] == 'P')
				{
					temp2.push_back(new powerplant(x, y));
				}
				if(city[i][j] == '-')
				{
					temp2.push_back(new road(x, y));
				}
				if(city[i][j] == '#')
				{
					temp2.push_back(new powered_road(x, y));
				}
			}
			map.push_back(temp2);
	}
}
