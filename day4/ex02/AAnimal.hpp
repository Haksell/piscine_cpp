#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include "Brain.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class AAnimal {
public:
	AAnimal();
	AAnimal(AAnimal const& aanimal);
	AAnimal& operator=(AAnimal const& aanimal);
	virtual ~AAnimal();

	virtual void makeSound() const = 0;
	std::string getType() const;

protected:
	std::string type;
};

#endif