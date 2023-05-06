#include "MateriaSource.hpp"
#include "ICharacter.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < MateriaSource::numSlots; ++i)
        this->slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
    *this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
    if (this != &materiaSource) {
        for (int i = 0; i < MateriaSource::numSlots; ++i) {
            delete this->slots[i];
            if (materiaSource.slots[i])
                this->slots[i] = materiaSource.slots[i]->clone();
            else
                this->slots[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MateriaSource::numSlots; ++i)
        delete this->slots[i];
}

void MateriaSource::learnMateria(AMateria *amateria) {
    if (!amateria)
        return;
    for (int i = 0; i < MateriaSource::numSlots; ++i) {
        if (!this->slots[i]) {
            this->slots[i] = amateria;
            return;
        }
    }
    delete amateria;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < MateriaSource::numSlots; ++i)
        if (this->slots[i] && this->slots[i]->getType() == type)
            return this->slots[i]->clone();
    return NULL;
}

const std::string MateriaSource::stringify() const {
    std::string s = "MateriaSource(";
    for (int i = 0; i < MateriaSource::numSlots; ++i) {
        if (i != 0)
            s += ", ";
        s += this->slots[i] ? this->slots[i]->getType() : "NULL";
    }
    s += ")";
    return s;
}

std::ostream &operator<<(std::ostream &os, MateriaSource const &materiaSource) {
    return os << materiaSource.stringify() << std::endl;
}