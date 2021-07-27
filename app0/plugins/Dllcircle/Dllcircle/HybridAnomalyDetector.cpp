#include "pch.h"

#include "HybridAnomalyDetector.h"

HybridAnomalyDetector::HybridAnomalyDetector() {
	// TODO Auto-generated constructor stub

}

HybridAnomalyDetector::~HybridAnomalyDetector() {
	// TODO Auto-generated destructor stub
	for (int i = 0; i < cf.size(); i++) {
		if (cf[i].corrlation > 0.5 && cf[i].corrlation < threshold) {
			delete cf[i].center;
		}
	}

}

correlatedFeatures HybridAnomalyDetector::checkThershold(const TimeSeries& ts, int size, float corre, Point** points, string a, string b) {
	correlatedFeatures c;
	if (corre > 0.5 && corre < threshold) {
		float max;
		Circle circle = findMinCircle(points, size);
		c.feature1 = a;
		c.feature2 = b;
		c.threshold = circle.radius * 1.1;
		c.center = new Point(circle.center);
		c.corrlation = corre; //add to the struct
		c.isEmpty = 1;
		return c;
	}
	else {
		c = SimpleAnomalyDetector::checkThershold(ts, size, corre, points, a, b);
		return c;
	}
}

bool HybridAnomalyDetector::helpDetect(Point* p, correlatedFeatures c) {
	if (c.corrlation > 0.5 && c.corrlation < threshold) {
		float dis = sqrt(pow(p->x - c.center->x, 2) + pow(p->y - c.center->y, 2));
		return (dis > c.threshold);
	}
	else {
		return SimpleAnomalyDetector::helpDetect(p, c);
	}
}

