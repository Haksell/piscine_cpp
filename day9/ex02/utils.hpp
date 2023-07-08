#pragma once

#include "mergeInsertion.hpp"
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <vector>

template <typename T>
std::string toString(T x) {
	std::stringstream ss;
	ss << x;
	return ss.str();
}

template <typename RandomAccessIterator>
void printContainer(RandomAccessIterator begin, RandomAccessIterator end,
					const std::string& title = "") {
	std::cout << title << '(';
	for (RandomAccessIterator it = begin; it != end; ++it) {
		if (it != begin)
			std::cout << ' ';
		std::cout << *it;
	}
	std::cout << ")\n";
}

template <typename RandomAccessIterator>
void testContainer(RandomAccessIterator begin, RandomAccessIterator end, const std::string& name,
				   bool verbose) {
	g_count = 0;
	struct timeval t0, t1;
	if (verbose)
		printContainer(begin, end, "Before: ");
	gettimeofday(&t0, NULL);
	mergeInsertion(begin, end);
	gettimeofday(&t1, NULL);
	double elapsed = (t1.tv_sec - t0.tv_sec) * 1000.0 + (t1.tv_usec - t0.tv_usec) / 1000.0;
	if (verbose)
		printContainer(begin, end, "After:  ");
	std::cout << "Time to process a range of " << std::distance(begin, end) << " elements with "
			  << name << std::fixed << std::setprecision(3) << elapsed << " ms for " << g_count
			  << " operations\n";
}