#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

#define FRAGTRAP_HITPOINTS 100
#define FRAGTRAP_ENERGYPOINTS 100
#define FRAGTRAP_ATTACKDAMAGE 30

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& fragTrap);
	~FragTrap();
	FragTrap& operator=(const FragTrap& fragTrap);

	void highFivesGuys();
};

std::ostream& operator<<(std::ostream& os, const FragTrap& fragTrap);

#endif
