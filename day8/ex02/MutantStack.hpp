#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return std::stack<T>::c.begin(); }
	const_iterator begin() const { return std::stack<T>::c.begin(); }

	iterator end() { return std::stack<T>::c.end(); }
	const_iterator end() const { return std::stack<T>::c.end(); }

	reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
	const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); }

	reverse_iterator rend() { return std::stack<T>::c.rend(); }
	const_reverse_iterator rend() const { return std::stack<T>::c.rend(); }
};

template <typename InputIterator>
void printIterator(InputIterator begin, InputIterator end) {
	std::cout << "{";
	bool is_first = true;
	for (InputIterator it = begin; it != end; ++it) {
		if (is_first)
			is_first = false;
		else
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "}\n";
}