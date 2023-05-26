#include "Array.hpp"

int main() {
	Array<int> empty;
	std::cout << empty << std::endl;

	Array<int> ints(ARR_INT_SIZE);
	std::cout << ints << std::endl;
	std::srand(std::time(NULL));
	for (int i = 0; i < ARR_INT_SIZE; ++i)
		ints[i] = std::rand() % 10;
	std::cout << ints << std::endl;

	try {
		ints[-1] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		ints[ARR_INT_SIZE] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Array<std::string> s1(3);
	std::cout << s1 << std::endl;
	s1[1] = "yolowesh";
	std::cout << s1 << std::endl;

	Array<std::string> s2 = s1;
	s2[0] = "Le temps est l'image mobile de la realite immobile.";
	s2[2] = "Pierre qui roule n'amasse pas mousse.";
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}