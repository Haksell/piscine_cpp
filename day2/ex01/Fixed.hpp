#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>
#define FIXED_BITS 8

class Fixed {
private:
	static int bits;
	int value;

public:
	Fixed();
	Fixed(const Fixed& fixed);
	Fixed(const int value);
	Fixed(const float value);

	~Fixed();
	Fixed& operator=(const Fixed& fixed);

	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif