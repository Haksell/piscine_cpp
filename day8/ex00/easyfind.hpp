#pragma once

#include <algorithm>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <vector>

#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"

template <typename T>
typename T::difference_type easyfind(const T& container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Value not found in container");
	return std::distance(container.begin(), it);
}

template <typename T>
void tryfind(const T& container, int value) {
	try {
		int index = easyfind(container, value);
		std::cout << "Found at index: " << index << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}