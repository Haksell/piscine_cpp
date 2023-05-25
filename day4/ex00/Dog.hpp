#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(Dog const& dog);
	Dog& operator=(Dog const& dog);
	~Dog();

	void makeSound() const;
};

#endif