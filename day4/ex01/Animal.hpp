#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Animal {
  public:
    Animal();
    Animal(Animal const &animal);
    Animal &operator=(Animal const &animal);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;

  protected:
    std::string type;
};

#endif