#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
  public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const &wrongAnimal);
    WrongAnimal &operator=(WrongAnimal const &wrongAnimal);
    ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;

  protected:
    std::string type;
};

#endif