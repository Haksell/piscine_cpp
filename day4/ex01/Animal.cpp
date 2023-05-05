#include "Animal.hpp"

Animal::Animal() : type("Animal") { std::cout << "Animal constructed.\n"; }

Animal::Animal(const Animal &animal) : type(animal.type) {
    std::cout << "Animal copied.\n";
}

Animal &Animal::operator=(Animal const &animal) {
    if (this != &animal)
        this->type = animal.type;
    std::cout << "Animal assigned.\n";
    return *this;
}

Animal::~Animal() { std::cout << "Animal destructed.\n"; }

void Animal::makeSound() const { std::cout << "???"; }

std::string Animal::getType() const { return this->type; }
