#include "Fixed.hpp"

int Fixed::bits = FIXED_BITS;
static float floatShift = (float)(1 << FIXED_BITS);

Fixed::Fixed() : value(0) { std::cout << "Default constructor called\n"; }
Fixed::Fixed(const Fixed &fixed) : value(fixed.value) {
    std::cout << "Copy constructor called\n";
}
Fixed::Fixed(const int value) : value(value << FIXED_BITS) {
    std::cout << "Int constructor called\n";
}
Fixed::Fixed(const float value) : value((int)roundf(floatShift * value)) {
    std::cout << "Float constructor called\n";
}

Fixed::~Fixed() { std::cout << "Destuctor called\n"; }

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called\n";
    this->value = fixed.value;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    this->value = raw;
}

float Fixed::toFloat() const { return this->value / floatShift; }
int Fixed::toInt() const { return this->value >> Fixed::bits; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}