#include "Fixed.hpp"

int Fixed::bits = FIXED_BITS;
static float floatShift = (float)(1 << FIXED_BITS);

Fixed::Fixed() : value(0) {}
Fixed::Fixed(const Fixed &fixed) : value(fixed.value) {}
Fixed::Fixed(const int value) : value(value << FIXED_BITS) {}
Fixed::Fixed(const float value) : value((int)roundf(floatShift * value)) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &fixed) {
    this->value = fixed.value;
    return *this;
}

int Fixed::getRawBits() const { return this->value; }
void Fixed::setRawBits(int const raw) { this->value = raw; }

float Fixed::toFloat() const { return this->value / floatShift; }
int Fixed::toInt() const { return this->value >> Fixed::bits; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->value > other.getRawBits();
}
bool Fixed::operator<(const Fixed &other) const {
    return this->value < other.getRawBits();
}
bool Fixed::operator>=(const Fixed &other) const {
    return this->value >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other) const {
    return this->value <= other.getRawBits();
}
bool Fixed::operator==(const Fixed &other) const {
    return this->value == other.getRawBits();
}
bool Fixed::operator!=(const Fixed &other) const {
    return this->value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) {
    return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) {
    return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) {
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator++() {
    ++this->value;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->value++;
    return temp;
}
Fixed Fixed::operator--() {
    --this->value;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->value--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a > b ? a : b;
}