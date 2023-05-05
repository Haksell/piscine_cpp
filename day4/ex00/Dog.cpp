#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(const Dog &dog) {
    this->type = dog.type;
    std::cout << "Dog constructed." << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructed." << std::endl; }

Dog &Dog::operator=(Dog const &dog) {
    if (this != &dog)
        this->type = dog.type;
    return *this;
}

void Dog::makeSound() const { std::cout << "woof" << std::endl; }
