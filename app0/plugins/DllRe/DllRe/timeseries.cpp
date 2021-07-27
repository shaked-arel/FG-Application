#include "pch.h"

/*
 * timeseries.cpp
 *
 * Author: 209531276, Shaked Arel
 */
#include "timeseries.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;
TimeSeries::TimeSeries(const char* CSVfileName) {
	std::string line;
	map<string, vector<float>> data1;
	std::vector<std::string> features;
	std::ifstream myfile(CSVfileName);
	getline(myfile, line);
	int end = line.find(",");
	std::string feature;
	//find headers of the features in the first line
	while (end != string::npos)
	{
		feature = line.substr(0, end);
		features.push_back(feature); //into vector
		data1[feature]; //into map
		line = line.substr(end + 1);
		end = line.find(",");
	}
	feature = line.substr(0, end);
	features.push_back(feature); //into vector
	data1[feature];
	int i = 0;
	while (getline(myfile, line)) { //find the values in each line 
		end = line.find(",");
		while (end != string::npos)
		{
			feature = line.substr(0, end);
			try { //for every header put the information in the correct vector
				data1[features[i]].push_back(::stof(feature.c_str()));
			}
			catch (exception ex) {}
			i++;
			line = line.substr(end + 1);
			end = line.find(",");
		}
		feature = line.substr(0, end);
		try {
			data1[features[i]].push_back(::stof(feature.c_str()));
		}
		catch (exception ex) {}
		i = 0;
	}
	myfile.close();
	this->data = data1;
}

