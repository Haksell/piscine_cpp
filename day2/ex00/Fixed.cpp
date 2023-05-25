#include "Fixed.hpp"

int Fixed::bits = 8;

Fixed::Fixed() : n(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const Fixed& fixed) : n(fixed.n) { std::cout << "Copy constructor called\n"; }

Fixed::~Fixed() { std::cout << "Destuctor called\n"; }

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called\n";
	this->n = fixed.n;
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return this->n;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->n = raw;
}