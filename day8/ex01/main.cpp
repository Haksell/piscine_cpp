#include "Span.hpp"

static void display_title(std::string s) {
	std::cout << BOLDBLUE << "--- " << s << " ---" << RESET << std::endl;
}

static void test(Span& span, int num) {
	if (num != 0) {
		try {
			span.addNumber(num);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
			return;
		}
	}

	std::cout << "longest" << span << " = ";
	try {
		std::cout << span.longestSpan();
	} catch (const std::exception& e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "shortest" << span << " = ";
	try {
		std::cout << span.shortestSpan();
	} catch (const std::exception& e) {
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;
}

static void testOneByOne() {
	display_title("ONE BY ONE");
	Span span = Span(8);
	test(span, 6);
	test(span, 3);
	test(span, 17);
	test(span, 9);
	test(span, INT_MAX);
	test(span, INT_MIN);
	test(span, INT_MAX - 2);
	test(span, INT_MIN + 1);
	test(span, 42);
}

static void testRange() {
	display_title("RANGE");
	Span span = Span(12);

	std::vector<int> vec;
	vec.push_back(27);
	vec.push_back(42);
	vec.push_back(69);
	span.addNumbers(vec.begin(), vec.end());
	test(span, 0);

	std::deque<int> deq;
	deq.push_back(1);
	deq.push_front(2);
	deq.push_back(3);
	deq.push_front(4);
	deq.push_back(5);
	deq.push_front(6);
	span.addNumbers(deq.begin(), deq.end());
	test(span, 0);

	try {
		span.addNumbers(deq.begin(), deq.end());
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	testOneByOne();
	testRange();
}