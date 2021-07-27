
#ifndef TIMESERIES_H_
#define TIMESERIES_H_
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class TimeSeries {
public:

	map<string, vector<float>> data;
	TimeSeries(const char* CSVfileName);
	void printTable();

};


#endif /* TIMESERIES_H_ */
