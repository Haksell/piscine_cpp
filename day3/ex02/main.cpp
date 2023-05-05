#include "FragTrap.hpp"

int main() {
    FragTrap ft0;
    FragTrap ft1 = ft0;
    FragTrap ft2(ft0);
    FragTrap ft3("Belzebuth");

    std::cout << std::endl;

    ft0.beRepaired(42);
    ft0.attack("Wololo");
    ft0.takeDamage(51);
    ft0.takeDamage(3);
    ft0.beRepaired(42);
    ft0.attack("Eustache");
    ft0.highFivesGuys();

    std::cout << std::endl;

    std::cout << "Name: " << ft0.getName() << std::endl;
    std::cout << "Hit points: " << ft0.getHitPoints() << std::endl;
    std::cout << "Energy points: " << ft0.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << ft0.getAttackDamage() << std::endl;

    std::cout << std::endl;
}