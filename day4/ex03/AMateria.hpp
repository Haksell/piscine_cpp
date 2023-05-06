#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria {
  public:
    AMateria(std::string const &type);
    AMateria(AMateria const &amateria);
    AMateria &operator=(AMateria const &amateria);
    virtual ~AMateria();

    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target) = 0;

  protected:
    AMateria();
    std::string type;
};

#endif