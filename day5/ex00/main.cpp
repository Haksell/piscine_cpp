#include "Bureaucrat.hpp"

static std::string getUser() {
	char* user = getenv("USER");
	return user ? user : "Anonymous";
}

int main() {
	try {
		Bureaucrat b1(getUser(), 1);
		std::cout << b1;
		b1.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b2;
		std::cout << b2;
		b2.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("b3", 160);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("b4", -5);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
