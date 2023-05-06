#include "AMateria.hpp"

AMateria::AMateria() {
    throw std::logic_error("Can't create an AMateria without type");
}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &amateria) : type(amateria.type) {}

AMateria &AMateria::operator=(AMateria const &amateria) {
    if (this != &amateria) {
        this->type = amateria.type;
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return this->type; }
