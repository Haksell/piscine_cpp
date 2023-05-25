#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << *this << " created." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << *this << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
	: name(clapTrap.getName()), hitPoints(clapTrap.getHitPoints()),
	  energyPoints(clapTrap.getEnergyPoints()), attackDamage(clapTrap.getAttackDamage()) {
	std::cout << *this << " created." << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << *this << " destroyed." << std::endl; }

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
	this->name = clapTrap.getName();
	this->hitPoints = clapTrap.getHitPoints();
	this->energyPoints = clapTrap.getEnergyPoints();
	this->attackDamage = clapTrap.getAttackDamage();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap) {
	os << "ClapTrap " << clapTrap.getName();
	return os;
}

bool ClapTrap::canMove() { return this->energyPoints > 0 && this->hitPoints > 0; }

std::string ClapTrap::getName() const { return this->name; }
unsigned int ClapTrap::getHitPoints() const { return this->hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return this->energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return this->attackDamage; }

void ClapTrap::attack(const std::string& target) {
	if (!this->canMove()) {
		std::cout << *this << " fails to attack " << target << "." << std::endl;
		return;
	}
	--this->energyPoints;
	std::cout << *this << " attacks " << target << ", causing " << this->attackDamage
			  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= this->hitPoints) {
		this->hitPoints = 0;
		std::cout << *this << " is now dead." << std::endl;
		return;
	}
	this->hitPoints -= amount;
	std::cout << *this << " has now " << this->hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->canMove()) {
		std::cout << *this << " fails to repair itself." << std::endl;
		return;
	}
	--this->energyPoints;
	this->hitPoints += amount;
	std::cout << *this << " has now " << this->hitPoints << " hit points." << std::endl;
}