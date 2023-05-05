#include "ClapTrap.hpp"

int main() {
    ClapTrap ct0;
    ClapTrap ct1 = ct0;
    ClapTrap ct2(ct0);
    ClapTrap ct3("Belzebuth");

    ct0.beRepaired(42);
    ct0.attack("Wololo");
    ct0.takeDamage(51);
    ct0.takeDamage(3);
    ct0.beRepaired(42);
    ct0.attack("Eustache");

    std::cout << "Name: " << ct0.getName() << std::endl;
    std::cout << "Hit points: " << ct0.getHitPoints() << std::endl;
    std::cout << "Energy points: " << ct0.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << ct0.getAttackDamage() << std::endl;
}