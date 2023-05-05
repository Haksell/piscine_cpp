#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructed.\n";
}

Cat::Cat(const Cat &cat) {
    this->type = cat.type;
    if (cat.brain == NULL)
        this->brain = NULL;
    else
        this->brain = new Brain(*cat.brain);
    std::cout << "Cat copied.\n";
}

Cat &Cat::operator=(Cat const &cat) {
    if (this != &cat) {
        delete this->brain;
        this->type = cat.type;
        if (cat.brain == NULL)
            this->brain = NULL;
        else
            this->brain = new Brain(*cat.brain);
    }
    std::cout << "Cat assigned.\n";
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructed.\n";
}

void Cat::makeSound() const { std::cout << "miaou" << std::endl; }

std::string Cat::getIdea(int idx) const {
    if (this->brain == NULL)
        throw std::logic_error("Brain pointer is NULL");
    if (idx < 0 || idx >= NUM_IDEAS)
        throw std::out_of_range("ideas[idx] is out of range");
    return this->brain->ideas[idx];
}

void Cat::setIdea(int idx, std::string idea) {
    if (this->brain == NULL)
        throw std::logic_error("Brain pointer is NULL");
    if (idx < 0 || idx >= NUM_IDEAS)
        throw std::out_of_range("ideas[idx] is out of range");
    this->brain->ideas[idx] = idea;
}
