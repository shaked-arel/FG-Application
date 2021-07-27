// 318770609	209531276

#ifndef MINCIRCLE_H_
#define MINCIRCLE_H_

#include <iostream>
#include <math.h>
#include <vector>
#include "anomaly_detection_util.h"

using namespace std;

// ------------ DO NOT CHANGE -----------

class Circle
{
public:
	Point center;
	float radius;
	Circle(Point c, float r) : center(c), radius(r) {}
};
// --------------------------------------


// implement
Circle findMinCircle(Point** points, size_t size);
float Disctance(Point p1, Point p2);
// you may add helper functions here

#endif /* MINCIRCLE_H_ */
