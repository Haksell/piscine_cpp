#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), FragTrap("Default_clap_name"),
      ScavTrap("Default_clap_name"), name("Default") {
    this->hitPoints = FRAGTRAP_HITPOINTS;
    this->energyPoints = SCAVTRAP_ENERGYPOINTS;
    this->attackDamage = FRAGTRAP_ATTACKDAMAGE;
    std::cout << *this << " created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"),
      ScavTrap(name + "_clap_name"), name(name) {
    this->hitPoints = FRAGTRAP_HITPOINTS;
    this->energyPoints = SCAVTRAP_ENERGYPOINTS;
    this->attackDamage = FRAGTRAP_ATTACKDAMAGE;
    std::cout << *this << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
    : name(diamondTrap.name) {
    this->ClapTrap::name = diamondTrap.ClapTrap::name;
    this->name = diamondTrap.name;
    this->hitPoints = diamondTrap.hitPoints;
    this->energyPoints = diamondTrap.energyPoints;
    this->attackDamage = diamondTrap.attackDamage;
    this->gateKeeperMode = diamondTrap.gateKeeperMode;
    std::cout << *this << " created." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
    this->ClapTrap::name = diamondTrap.ClapTrap::name;
    this->name = diamondTrap.name;
    this->hitPoints = diamondTrap.hitPoints;
    this->energyPoints = diamondTrap.energyPoints;
    this->attackDamage = diamondTrap.attackDamage;
    this->gateKeeperMode = diamondTrap.gateKeeperMode;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << *this << " destroyed." << std::endl;
}

std::string DiamondTrap::getName() const { return this->name; }

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << this->name << " and my ClapTrap name is "
              << ClapTrap::getName() << "." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const DiamondTrap &diamondTrap) {
    os << "DiamondTrap " << diamondTrap.getName();
    return os;
}
