#include "pch.h"
#include "minCircle.h"

Point FindMiddle(Point p1, Point p2)
{
	float middle_x = (p1.x + p2.x) / 2;
	float middle_y = (p1.y + p2.y) / 2;
	return Point(middle_x, middle_y);
}

float Disctance(Point p1, Point p2)
{
	float x2 = (p1.x - p2.x) * (p1.x - p2.x);
	float y2 = (p1.y - p2.y) * (p1.y - p2.y);
	return sqrt(x2 + y2);
}

int is_in(Circle c, Point p)
{
	float d = Disctance(c.center, p);
	if (d <= c.radius)
	{
		return 1;
	}
	return 0;
}

Circle GetFrom3(Point p1, Point p2, Point p3)
{
	float a = p2.x - p1.x;
	float b = p2.y - p1.y;
	float c = p3.x - p1.x;
	float d = p3.y - p1.y;
	float A = pow(a, 2) + pow(b, 2);
	float B = pow(c, 2) + pow(d, 2);
	float C = a * d - b * c;
	Point p = Point((d * A - b * B) / (2 * C), (a * B - c * A) / (2 * C));
	p.x += p1.x;
	p.y += p1.y;
	return Circle(p, Disctance(p, p1));
}

Circle Check(Point* points, int size) {
	if (size == 0) {
		return Circle(Point(0, 0), 0);
	}
	if (size == 1)
	{
		return Circle(points[0], 0);
	}
	if (size == 2)
	{
		return Circle(FindMiddle(points[0], points[1]), Disctance(points[0], points[1]) / 2);
	}
	Circle temp = Circle(FindMiddle(points[0], points[1]), Disctance(points[0], points[1]) / 2);
	if (is_in(temp, points[2]) == 1)
	{
		return temp;
	}
	temp = Circle(FindMiddle(points[1], points[2]), Disctance(points[1], points[2]) / 2);
	if (is_in(temp, points[0]) == 1)
	{
		return temp;
	}
	temp = Circle(FindMiddle(points[0], points[2]), Disctance(points[0], points[2]) / 2);
	if (is_in(temp, points[1]) == 1)
	{
		return temp;
	}
	return GetFrom3(points[0], points[1], points[2]);
}
Circle findCircle(Point** points, vector<Point> R, size_t size)
{
	if (R.size() == 3 || size == 0) {
		return Check(R.data(), R.size());
	}
	Point p = *points[size - 1];
	Circle c = findCircle(points, R, (size - 1));
	if (is_in(c, p) == 1)
	{
		return c;
	}
	R.push_back(p);
	return findCircle(points, R, (size - 1));
}


// implement
Circle findMinCircle(Point** points, size_t size)
{
	vector<Point> R;
	return findCircle(points, R, size);
}