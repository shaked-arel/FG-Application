

#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"

class HybridAnomalyDetector :public SimpleAnomalyDetector {
public:
	HybridAnomalyDetector();
	virtual ~HybridAnomalyDetector();
protected:
	virtual correlatedFeatures checkThershold(const TimeSeries& ts, int size, float corre, Point** points, string a, string b) override;
	virtual bool helpDetect(Point* p, correlatedFeatures cf);
};

#endif /* HYBRIDANOMALYDETECTOR_H_ */
