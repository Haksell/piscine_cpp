#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character() : name("Jean-Luc Melenchon") {
    for (int i = 0; i < Character::numSlots; ++i)
        this->slots[i] = NULL;
}

Character::Character(const std::string &name) : name(name) {
    for (int i = 0; i < Character::numSlots; ++i)
        this->slots[i] = NULL;
}

Character::Character(Character const &character) {
    this->name = character.name;
    for (int i = 0; i < Character::numSlots; ++i) {
        if (character.slots[i])
            this->slots[i] = character.slots[i]->clone();
        else
            this->slots[i] = NULL;
    }
}

Character &Character::operator=(Character const &character) {
    if (this != &character) {
        this->name = character.name;
        for (int i = 0; i < Character::numSlots; ++i) {
            delete this->slots[i];
            if (character.slots[i])
                this->slots[i] = character.slots[i]->clone();
            else
                this->slots[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < Character::numSlots; ++i)
        delete this->slots[i];
}

std::string const &Character::getName() const { return this->name; };

void Character::equip(AMateria *m) {
    for (int i = 0; i < Character::numSlots; ++i) {
        if (!this->slots[i]) {
            this->slots[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < Character::numSlots)
        this->slots[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < Character::numSlots && this->slots[idx])
        this->slots[idx]->use(target);
}

const std::string Character::stringify() const {
    std::string s = "Character=" + this->name + "(";
    for (int i = 0; i < Character::numSlots; ++i) {
        if (i != 0)
            s += ", ";
        s += this->slots[i] ? this->slots[i]->getType() : "NULL";
    }
    s += ")";
    return s;
}

std::ostream &operator<<(std::ostream &os, Character const &character) {
    return os << character.stringify() << std::endl;
}
