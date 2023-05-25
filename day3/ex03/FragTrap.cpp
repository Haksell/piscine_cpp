#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << *this << " created." << std::endl;
	this->hitPoints = FRAGTRAP_HITPOINTS;
	this->energyPoints = FRAGTRAP_ENERGYPOINTS;
	this->attackDamage = FRAGTRAP_ATTACKDAMAGE;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << *this << " created." << std::endl;
	this->hitPoints = FRAGTRAP_HITPOINTS;
	this->energyPoints = FRAGTRAP_ENERGYPOINTS;
	this->attackDamage = FRAGTRAP_ATTACKDAMAGE;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap) {
	std::cout << *this << " created." << std::endl;
}

FragTrap::~FragTrap() { std::cout << *this << " destroyed." << std::endl; }

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
	this->name = fragTrap.name;
	this->hitPoints = fragTrap.hitPoints;
	this->energyPoints = fragTrap.energyPoints;
	this->attackDamage = fragTrap.attackDamage;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const FragTrap& fragTrap) {
	os << "FragTrap " << fragTrap.getName();
	return os;
}

void FragTrap::highFivesGuys() {
	std::cout << *this << " requests a high five! Pleeeeeease (｡♥‿♥｡)" << std::endl;
}
