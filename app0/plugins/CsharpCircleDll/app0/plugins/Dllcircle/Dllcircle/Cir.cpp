#include "pch.h"
#include "Cir.h"
#include "HybridAnomalyDetector.h"

Cir::Cir(const char* a) {
	this->name = a;
}
const char* Cir::Find(const char* csvPath) {
	HybridAnomalyDetector h;
	h.learnNormal(TimeSeries(name));
	vector<AnomalyReport> v = h.detect(TimeSeries(csvPath));
	ofstream out;
	string str;
	out.open("report_file");
	for (int i = 0; i < v.size(); i++) {
		out << v[i].description << "--"<< v[i].timeStep << "\n";
	}
	out.close();
	return "report_file";
}