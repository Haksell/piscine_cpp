#include "utils.hpp"
#include <cstdlib>
#include <deque>
#include <stdexcept>
#include <vector>

#define EXHAUSTIVE_LIMIT 7
#define MAX_TEST_SIZE 400
#define RANDOM_MIN 1
#define RANDOM_MAX 100
#define RANDOM_SEED 42

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"

static bool equalVectors(const std::vector<std::size_t>& v1, const std::vector<std::size_t>& v2) {
	if (v1.size() != v2.size())
		return false;
	for (size_t i = 0; i < v1.size(); ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

static bool check(const std::vector<std::size_t>& current) {
	std::vector<std::size_t> target = current;
	std::sort(target.begin(), target.end());
	std::vector<std::size_t> cpy = current;
	std::deque<std::size_t> deq(cpy.begin(), cpy.end());
	mergeInsertion(cpy.begin(), cpy.end());
	mergeInsertion(deq.begin(), deq.end());
	if (!equalVectors(cpy, target) ||
		!equalVectors(std::vector<std::size_t>(deq.begin(), deq.end()), target)) {
		printContainer(current.begin(), current.end());
		printContainer(cpy.begin(), cpy.end());
		printContainer(deq.begin(), deq.end());
		std::cout << std::endl;
		return false;
	}
	return true;
}

static bool testExhaustive(std::size_t size, std::vector<std::size_t>& current) {
	if (current.size() == size)
		return check(current);
	bool success = true;
	for (std::size_t i = 0; i < size; ++i) {
		current.push_back(i);
		success &= testExhaustive(size, current);
		current.pop_back();
	}
	return success;
}

static size_t getRandomSizeT() {
	static size_t x = RANDOM_SEED;

	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return (x);
}

static size_t getRandomSizeT(size_t min, size_t max) {
	if (max < min)
		throw std::invalid_argument("min is greater than max");
	const size_t diff = max - min;
	return min + getRandomSizeT() % diff;
}

static std::vector<std::size_t> getRandomVector(size_t size) {
	std::vector<std::size_t> r(size);
	for (size_t i = 0; i < size; ++i)
		r[i] = getRandomSizeT(RANDOM_MIN, RANDOM_MAX);
	return r;
}

static bool testRandom() {
	bool success = true;
	for (std::size_t size = EXHAUSTIVE_LIMIT; size < MAX_TEST_SIZE; ++size) {
		std::vector<std::size_t> randomVector = getRandomVector(size);
		success &= check(randomVector);
	}
	return success;
}

static std::string color(size_t c, const std::string& s) {
	return BOLD "\033[3" + toString(c) + "m" + s + RESET;
}

bool test() {
	bool success = true;
	std::vector<std::size_t> current;
	for (std::size_t size = 0; size < EXHAUSTIVE_LIMIT; ++size) {
		if (testExhaustive(size, current))
			std::cout << "Every container of size " << color(size, toString(size))
					  << " has been checked.\n";
		else
			success = false;
	}
	if (testRandom()) {
		const std::string congrats = "Random tests successful.";
		for (size_t i = 0; i < congrats.size(); ++i)
			std::cout << color(1 + i % 6, toString(congrats[i]));
		std::cout << std::endl;
	} else
		success = false;
	return success;
}
