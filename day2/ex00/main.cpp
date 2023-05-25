#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed b(a);
	b.setRawBits(42);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	c.setRawBits(257);
	std::cout << c.getRawBits() << std::endl;
}