#include "mergeInsertion.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <deque>
#include <stdexcept>
#include <vector>

int g_count = 0;

bool test();

static bool parseSizeT(const std::string& s, std::size_t& out) {
	std::istringstream iss(s);
	iss >> out;
	return iss.eof() && !iss.fail();
}

int main(int argc, char** argv) {
	if (argc == 1)
		return test() ? EXIT_SUCCESS : EXIT_FAILURE;
	std::vector<std::size_t> vec;
	for (int i = 1; i < argc; ++i) {
		std::size_t n;
		if (!parseSizeT(argv[i], n) || n == 0) {
			std::cerr << "Error: invalid number: " << argv[i] << std::endl;
			return EXIT_FAILURE;
		}
		vec.push_back(n);
	}
	std::deque<std::size_t> deq(vec.begin(), vec.end());
	testContainer(vec.begin(), vec.end(), "std::vector: ", true);
	testContainer(deq.begin(), deq.end(), "std::deque:  ", false);
}