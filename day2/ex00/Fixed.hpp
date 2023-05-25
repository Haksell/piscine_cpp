#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	static int bits;
	int n;

public:
	Fixed();
	Fixed(const Fixed& fixed);
	~Fixed();
	Fixed& operator=(const Fixed& fixed);

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif