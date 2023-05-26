#include "Span.hpp"

Span::Span(unsigned int N) : _capacity(N) {}

Span::Span(const Span& other) : _capacity(other._capacity), _numbers(other._numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_capacity = other._capacity;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int number) {
	if (_numbers.size() >= _capacity)
		throw std::length_error("Span is already full.");
	_numbers.insert(number);
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::length_error("Span must contain at least two _numbers.");

	std::multiset<int>::const_iterator it = _numbers.begin();
	int previous = *it;
	unsigned int min_span = *++it - previous;
	while (++it != _numbers.end()) {
		unsigned int span = *it - previous;
		if (span < min_span)
			min_span = span;
		previous = *it;
	}

	return min_span;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::length_error("Span must contain at least two _numbers.");

	return *_numbers.rbegin() - *_numbers.begin();
}

size_t Span::getCapacity() const { return _capacity; }

size_t Span::getSize() const { return _numbers.size(); }

const std::multiset<int>& Span::getNumbers() const { return _numbers; }

std::ostream& operator<<(std::ostream& os, const Span& arr) {
	const std::multiset<int>& numbers = arr.getNumbers();
	os << "Span(";
	bool is_first = true;
	for (std::multiset<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
		if (is_first)
			is_first = false;
		else
			os << ", ";
		os << *it;
	}
	os << ")";
	return os;
}
