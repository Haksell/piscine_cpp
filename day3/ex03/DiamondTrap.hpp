#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
  private:
    std::string name;

  public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &diamondTrap);
    ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &diamondTrap);

    std::string getName() const;

    void whoAmI();
};

std::ostream &operator<<(std::ostream &os, const DiamondTrap &diamondTrap);

#endif