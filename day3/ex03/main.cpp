#include "DiamondTrap.hpp"

int main() {
    DiamondTrap dt0("Belzebuth");
    DiamondTrap dt1 = dt0;
    DiamondTrap dt2(dt0);
    DiamondTrap dt3;

    std::cout << std::endl;

    dt0.beRepaired(42);
    dt0.attack("Wololo");
    dt0.takeDamage(51);
    dt0.takeDamage(3);
    dt0.beRepaired(42);
    dt0.attack("Eustache");
    dt0.highFivesGuys();
    dt0.whoAmI();
    dt0.takeDamage(1000);
    dt0.attack("Jean-Eude");
    dt0.guardGate();
    dt0.guardGate();

    std::cout << std::endl;

    std::cout << "Name: " << dt0.getName() << std::endl;
    std::cout << "Clap Trap Name: " << dt0.ClapTrap::getName() << std::endl;
    std::cout << "Hit points: " << dt0.getHitPoints() << std::endl;
    std::cout << "Energy points: " << dt0.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << dt0.getAttackDamage() << std::endl;

    std::cout << std::endl;
}