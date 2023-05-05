#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), gateKeeperMode(false) {
    std::cout << *this << " created." << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gateKeeperMode(false) {
    std::cout << *this << " created." << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
    : ClapTrap(scavTrap), gateKeeperMode(scavTrap.gateKeeperMode) {
    std::cout << *this << " created." << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << *this << " destroyed." << std::endl; }

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    this->gateKeeperMode = scavTrap.gateKeeperMode;
    this->name = scavTrap.name;
    this->hitPoints = scavTrap.hitPoints;
    this->energyPoints = scavTrap.energyPoints;
    this->attackDamage = scavTrap.attackDamage;
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << *this << " is " << (this->gateKeeperMode ? "already" : "now")
              << " in Gate keeper mode." << std::endl;
    this->gateKeeperMode = true;
}

void ScavTrap::attack(const std::string &target) {
    if (!this->canMove()) {
        std::cout << *this << " fails to attack " << target << "." << std::endl;
        return;
    }
    --this->energyPoints;
    std::cout << *this << " attacks " << target << ", causing "
              << this->attackDamage << " points of damage!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap) {
    os << "ScavTrap " << scavTrap.getName();
    return os;
}
