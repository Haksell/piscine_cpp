#include "easyfind.hpp"

static void display_title(std::string s) {
	std::cout << BOLDBLUE << "--- " << s << " ---" << RESET << std::endl;
}

static void testVector() {
	display_title("VECTOR TESTS");
	std::vector<int> numbers;
	numbers.push_back(5);
	numbers.push_back(10);
	numbers.push_back(12);
	numbers.push_back(8);
	numbers.push_back(7);
	tryfind(numbers, 5);
	tryfind(numbers, 12);
	tryfind(numbers, 7);
	tryfind(numbers, 13);
}

static void testDeque() {
	display_title("DEQUE TESTS");
	std::deque<int> numbers;
	tryfind(numbers, 5);
	numbers.push_back(5);
	tryfind(numbers, 5);
	numbers.push_front(42);
	tryfind(numbers, 5);
}

int main() {
	testVector();
	testDeque();
}