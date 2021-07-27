#include "pch.h"
/*
 * anomaly_detection_util.cpp
 *
 * Author: 209531276, Shaked Arel
 */
#include <math.h>
#include "anomaly_detection_util.h"
#include <stdlib.h>

 //returns the average
float avg(float* x, int size) {
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += x[i];
	}
	return sum / size;
}

// returns the variance of X and Y
float var(float* x, int size) {
	float sum = 0;
	float miu = avg(x, size);
	for (int i = 0; i < size; i++) {
		sum += pow(x[i], 2);
	}
	return  (sum / size) - (pow(miu, 2));
}

// returns the covariance of X and Y
float cov(float* x, float* y, int size) {
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += x[i] * y[i];
	}
	return (sum / size) - (avg(x, size) * avg(y, size));
}

// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size) {
	return cov(x, y, size) / (sqrt(var(x, size)) * sqrt(var(y, size)));
}

// performs a linear regression and return s the line equation
Line linear_reg(Point** points, int size) {
	float* x = new float[size];
	float *y=new float[size];
	for (int i = 0; i < size; i++) {
		x[i] = points[i]->x;
		y[i] = points[i]->y;
	}
	float a = cov(x, y, size) / var(x, size);
	float b = avg(y, size) - a * avg(x, size);
	return Line(a, b);
}

// returns the deviation between point p and the line
float dev(Point p, Line l) {
	return fabs((l.f(p.x) - p.y));
}

// returns the deviation between point p and the line equation of the points
float dev(Point p, Point** points, int size) {
	Line l = linear_reg(points, size);
	return dev(p, l);
}
