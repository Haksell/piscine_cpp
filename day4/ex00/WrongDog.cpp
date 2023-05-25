#include "WrongDog.hpp"

WrongDog::WrongDog() {
	this->type = "WrongDog";
	std::cout << "WrongDog constructed." << std::endl;
}

WrongDog::WrongDog(const WrongDog& wrongDog) {
	this->type = wrongDog.type;
	std::cout << "WrongDog constructed." << std::endl;
}

WrongDog::~WrongDog() { std::cout << "WrongDog destructed." << std::endl; }

WrongDog& WrongDog::operator=(WrongDog const& wrongDog) {
	if (this != &wrongDog)
		this->type = wrongDog.type;
	return *this;
}

void WrongDog::makeSound() const { std::cout << "woof" << std::endl; }
