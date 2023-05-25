#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
public:
	WrongDog();
	WrongDog(WrongDog const& wrongDog);
	WrongDog& operator=(WrongDog const& wrongDog);
	~WrongDog();

	void makeSound() const;
};

#endif