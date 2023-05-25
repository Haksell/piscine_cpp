#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal {
public:
	Cat();
	Cat(Cat const& cat);
	Cat& operator=(Cat const& cat);
	~Cat();

	void makeSound() const;
	std::string getIdea(int idx) const;
	void setIdea(int idx, std::string idea);

private:
	Brain* brain;
};

#endif