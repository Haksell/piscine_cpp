#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructed.\n";
}

Dog::Dog(const Dog &dog) {
    this->type = dog.type;
    if (dog.brain == NULL)
        this->brain = NULL;
    else
        this->brain = new Brain(*dog.brain);
    std::cout << "Dog copied.\n";
}

Dog &Dog::operator=(Dog const &dog) {
    if (this != &dog) {
        delete this->brain;
        this->type = dog.type;
        if (dog.brain == NULL)
            this->brain = NULL;
        else
            this->brain = new Brain(*dog.brain);
    }
    std::cout << "Dog assigned.\n";
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructed.\n";
}

void Dog::makeSound() const { std::cout << "woof" << std::endl; }

std::string Dog::getIdea(int idx) const {
    if (this->brain == NULL)
        throw std::logic_error("Brain pointer is NULL");
    if (idx < 0 || idx >= NUM_IDEAS)
        throw std::out_of_range("ideas[idx] is out of range");
    return this->brain->ideas[idx];
}

void Dog::setIdea(int idx, std::string idea) {
    if (this->brain == NULL)
        throw std::logic_error("Brain pointer is NULL");
    if (idx < 0 || idx >= NUM_IDEAS)
        throw std::out_of_range("ideas[idx] is out of range");
    this->brain->ideas[idx] = idea;
}
