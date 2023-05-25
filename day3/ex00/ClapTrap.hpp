#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

	bool canMove();

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& clapTrap);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& clapTrap);

	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap);

#endif