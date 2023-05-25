#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define NUM_IDEAS 100

class Brain {
public:
	Brain();
	Brain(Brain const& brain);
	Brain& operator=(Brain const& brain);
	~Brain();
	std::string ideas[NUM_IDEAS];
};

#endif