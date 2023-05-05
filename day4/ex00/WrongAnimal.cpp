#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
    : type(wrongAnimal.type) {
    std::cout << "WrongAnimal constructed." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &wrongAnimal) {
    if (this != &wrongAnimal)
        this->type = wrongAnimal.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructed." << std::endl;
}

void WrongAnimal::makeSound() const { std::cout << "???" << std::endl; }

std::string WrongAnimal::getType() const { return this->type; }
