#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructed." << std::endl;
}

Animal::Animal(const Animal &animal) : type(animal.type) {
    std::cout << "Animal constructed." << std::endl;
}

Animal &Animal::operator=(Animal const &animal) {
    if (this != &animal)
        this->type = animal.type;
    return *this;
}

Animal::~Animal() { std::cout << "Animal destructed." << std::endl; }

void Animal::makeSound() const { std::cout << "???" << std::endl; }

std::string Animal::getType() const { return this->type; }
