#include "pch.h"
#include "Regresion.h"
#include "SimpleAnomalyDetector.h"


Reg::Reg(const char* CSVfileName) {
	this->name = CSVfileName;
}
const char* Reg::findDetect(const char* csvPath,const char* path) {
	SimpleAnomalyDetector s;
	s.learnNormal(TimeSeries(path));
	vector<AnomalyReport> v = s.detect(TimeSeries(csvPath));
	ofstream out;
	out.open("report_file");
	for (int i = 0; i < v.size(); i++) {
		out << v[i].description << "--" << v[i].timeStep << "\n";
	}
	out.close();
	return "report_file";
}
