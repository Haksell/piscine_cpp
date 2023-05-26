#pragma once

#include <climits>
#include <deque>
#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"

class Span {
public:
	Span(unsigned int N);
	Span(const Span& other);
	~Span();
	Span& operator=(const Span& other);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	size_t getCapacity() const;
	size_t getSize() const;
	const std::multiset<int>& getNumbers() const;

	void addNumber(int number);

	template <typename InputIterator>
	void addNumbers(InputIterator begin, InputIterator end) {
		for (InputIterator it = begin; it != end; ++it)
			addNumber(*it);
	}

private:
	Span();
	size_t _capacity;
	std::multiset<int> _numbers;
};

std::ostream& operator<<(std::ostream& os, const Span& arr);