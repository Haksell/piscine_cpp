#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(WrongCat const& wrongWrongCat);
	WrongCat& operator=(WrongCat const& wrongWrongCat);
	~WrongCat();

	void makeSound() const;
};

#endif