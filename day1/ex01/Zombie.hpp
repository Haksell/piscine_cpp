#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class Zombie {
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	void announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif