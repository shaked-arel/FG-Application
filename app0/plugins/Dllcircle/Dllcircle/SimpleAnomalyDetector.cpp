#include "pch.h"
/*
 * SimpleAnomalyDetector.cpp
 *
 * Author: 209531276, Shaked Arel
 */
#include "SimpleAnomalyDetector.h"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
	// TODO Auto-generated constructor stub
	threshold = 0.9;
}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
	// TODO Auto-generated destructor stub
}

/*get the threshold by calculating the max between all the points*/
float SimpleAnomalyDetector::FindThreshold(Point** points, Line line, int size) {
	float max = 0;
	float current;
	for (int i = 0; i < size; i++) {
		current = dev(*points[i], line);
		if (current > max) {
			max = current;
		}
	}
	return max;
}

correlatedFeatures SimpleAnomalyDetector::checkThershold(const TimeSeries& ts, int size, float corre, Point** points, string a, string b) {
	if (corre >= threshold) { //check if the features are correlative
		float max;
		Line l;
		l = linear_reg(points, size); //create the line
		max = SimpleAnomalyDetector::FindThreshold(points, l, size);
		correlatedFeatures c;
		c.feature1 = a;
		c.feature2 = b;
		c.lin_reg = l;
		c.threshold = max;
		c.center = NULL;
		c.corrlation = corre; //add to the struct
		c.isEmpty = 1;
		return c;
		//cf.push_back(c); //push into the vector
	}
	correlatedFeatures c;
	c.isEmpty = 0;
	return c;
}

void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts) {
	float corre;
	int size;
	correlatedFeatures c;
	// TODO Auto-generated destructor stub
	for (auto i = ts.data.begin(); i != ts.data.end(); ++i) { //go over the keys of the map
		size = i->second.size();//get the size of a vector
		for (auto j = std::next(i, 1); j != ts.data.end(); ++j) { //go over the keys +1
			float* arr= new float[size];
			float* brr= new float[size];
			for (int i1 = 0; i1 < size; i1++) { //create an array from the vectors
				arr[i1] = i->second[i1];
				brr[i1] = j->second[i1];
			}
			corre = pearson(arr, brr, size);
			Point** points = new Point * [size];
			for (int k = 0; k < size; k++) { //create an array of pointers to points
				Point* ptr = new Point(arr[k], brr[k]);
				points[k] = ptr;
			}
			c = checkThershold(ts, size, abs(corre), points, i->first, j->first);
			if (c.isEmpty == 1) {
				cf.push_back(c);
			}
			for (int k = 0; k < size; k++) { //delete
				delete points[k];
			}
			delete[]points;
		}
	}
}

bool SimpleAnomalyDetector::helpDetect(Point* p, correlatedFeatures cf) {
	return (dev(*p, cf.lin_reg) > (cf.threshold * 1.2));
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts) {
	// TODO Auto-generated destructor stub
	std::string first;
	std::string second;
	float x, y;
	int size_cf = cf.size(), size_vec;
	vector<AnomalyReport> var;
	for (int i = 0; i < size_cf; i++) { //go over the cf vector
		first = cf[i].feature1;
		second = cf[i].feature2;
		size_vec = ts.data.at(first).size();
		for (int j = 0; j < size_vec; j++) { //go over the vectors
			x = ts.data.at(first)[j];
			y = ts.data.at(second)[j];
			Point* p = new Point(x, y);
			if (helpDetect(p, cf[i])) { //check if there was a problem
				AnomalyReport ar = AnomalyReport(first + "-" + second, j + 1);
				var.push_back(ar); //add the  information of the problem to the vector
			}
			delete p;
		}
	}
	return var;
}

