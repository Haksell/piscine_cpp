#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}
Point::Point(const Point& point) : x(point.x), y(point.y) {}
Point::Point(const int x, const int y) : x(Fixed(x)), y(Fixed(y)) {}
Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}
Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}
Point::~Point() {}

Point& Point::operator=(const Point& other) {
	if (this == &other)
		return *this;
	const_cast<Fixed&>(x) = other.x;
	const_cast<Fixed&>(y) = other.y;
	return *this;
}

Fixed Point::getX() const { return this->x; }
Fixed Point::getY() const { return this->y; }

bool Point::operator==(const Point& other) const {
	return this->x == other.getX() && this->y == other.getY();
}
bool Point::operator!=(const Point& other) const {
	return this->x != other.getX() || this->x == other.getY();
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << '(' << point.getX() << ',' << point.getY() << ')';
	return os;
}
