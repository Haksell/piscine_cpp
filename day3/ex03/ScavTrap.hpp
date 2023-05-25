#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define SCAVTRAP_HITPOINTS 100
#define SCAVTRAP_ENERGYPOINTS 50
#define SCAVTRAP_ATTACKDAMAGE 20

class ScavTrap : virtual public ClapTrap {
protected:
	bool gateKeeperMode;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& scavTrap);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& scavTrap);

	void attack(const std::string& target);
	void guardGate();
};

std::ostream& operator<<(std::ostream& os, const ScavTrap& scavTrap);

#endif
