#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "definitions.hpp";
using namespace std;

void fileio(string filename, vector<vector<zone*>> &map)
{
	ifstream  in_f;
	vector<string> data;
	vector<vector<char>> city;
	string line, temp, filename;
	int position, refresh, time;
	int row = 0;

	in_f.open(config);

	while(getline(in_f,line))
	{
		position = line.find(":");
		temp = line.substr(position + 1);
		data.push_back(temp);

		temp = "";
	}
	in_f.close();

	filename = data[0];
	time = stoi(data[1]);
	refresh = stoi(data[2]);

	in_f.open(filename);

	while(getline(in_f,line))
	{
		vector<char> temp1;
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

	for(int i = 0; i < city.size(); i++)
	{
			vector<zone*> temp2;
			for(int j = 0; j < city[i].size(); j++)
			{
				y = i;
				x = j;
				if(city[i][j] == ' ')
					continue;
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

				map->map_grid.push_back(zones);
			}

			map.at(i).push_back(temp2);
	}

}
