#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) {
	this->type = wrongCat.type;
	std::cout << "WrongCat constructed." << std::endl;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructed." << std::endl; }

WrongCat& WrongCat::operator=(WrongCat const& wrongCat) {
	if (this != &wrongCat)
		this->type = wrongCat.type;
	return *this;
}

void WrongCat::makeSound() const { std::cout << "miaou" << std::endl; }
