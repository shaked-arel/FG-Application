

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

struct correlatedFeatures {
	string feature1, feature2;  // names of the correlated features
	float corrlation;
	Line lin_reg;
	float threshold;
	Point* center;
	int isEmpty; //0 if empty 1 otherwise
};


class SimpleAnomalyDetector :public TimeSeriesAnomalyDetector {
public:
	SimpleAnomalyDetector();
	virtual ~SimpleAnomalyDetector();

	virtual void learnNormal(const TimeSeries& ts);
	virtual vector<AnomalyReport> detect(const TimeSeries& ts);

	float getThershold() {
		return threshold;
	}

	void setThershold(float x) {
		threshold = x;
	}

	vector<correlatedFeatures> getNormalModel() {
		return cf;
	}
protected:
	vector<correlatedFeatures> cf;
	float threshold;
	virtual correlatedFeatures checkThershold(const TimeSeries& ts, int size, float corre, Point** points, string a, string b);
	float FindThreshold(Point** points, Line line, int size);
	virtual bool helpDetect(Point* p, correlatedFeatures cf);
};



#endif /* SIMPLEANOMALYDETECTOR_H_ */
