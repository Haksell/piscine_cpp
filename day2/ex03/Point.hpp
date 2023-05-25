#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const Point& point);
	Point(const int x, const int y);
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);

	~Point();
	Point& operator=(const Point& point);

	Fixed getX() const;
	Fixed getY() const;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;
};

std::ostream& operator<<(std::ostream& os, const Point& point);

#endif