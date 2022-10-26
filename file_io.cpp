#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector fileIO(string config)
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
	return city;
}
