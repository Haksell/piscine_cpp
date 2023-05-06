#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  public:
    const static int numSlots = 4;

    MateriaSource();
    MateriaSource(const MateriaSource &materiaSource);
    MateriaSource &operator=(const MateriaSource &materiaSource);
    ~MateriaSource();

    void learnMateria(AMateria *amateria);
    AMateria *createMateria(std::string const &type);
    const std::string stringify() const;

  private:
    AMateria *slots[MateriaSource::numSlots];
};

std::ostream &operator<<(std::ostream &os, MateriaSource const &materiaSource);

#endif