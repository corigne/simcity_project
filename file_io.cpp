#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector fileIO(string config, zone &map)
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
			for(int j = 0; j < city[i].size; j++)
			{
				y = i;
				x = j;
				if(city[i][j] == ' ')
					continue;
				if(city[i][j] == 'I')
				{
					industrial tempi(x, y);
					map.push_back(tempi);
				}
				if(city[i][j] == 'R')
				{
					residential tempr(x, y);
					map.push_back(tempr);
				}
				if(city[i][j] == 'C')
				{
					commercial tempc(xy);
					map.push_back(tempc);
				}
				if(city[i][j] == 'T')
				{
					commercial tempt(xy);
					map.push_back(tempt);
				}
				if(city[i][j] == 'P')
				{
					commercial tempc(xy);
					map.push_back(tempc);
				}
				if(city[i][j] == '-')
				{
					road tempr(xy);
					map.push_back(tempr);
				}
				if(city[i][j] == '#')
				{
					powerplant temppow(xy);
					map.push_back(temppow);
				}
			}
	}

	return city;
}
