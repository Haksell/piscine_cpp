#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
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
