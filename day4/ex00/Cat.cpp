#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(const Cat &cat) {
    this->type = cat.type;
    std::cout << "Cat constructed." << std::endl;
}

Cat::~Cat() { std::cout << "Cat destructed." << std::endl; }

Cat &Cat::operator=(Cat const &cat) {
    if (this != &cat)
        this->type = cat.type;
    return *this;
}

void Cat::makeSound() const { std::cout << "miaou" << std::endl; }
