#include "ScavTrap.hpp"

int main() {
    ScavTrap st0;
    ScavTrap st1 = st0;
    ScavTrap st2(st0);
    ScavTrap st3("Belzebuth");

    std::cout << std::endl;

    st0.beRepaired(42);
    st0.attack("Wololo");
    st0.takeDamage(51);
    st0.takeDamage(3);
    st0.beRepaired(42);
    st0.attack("Eustache");
    st0.guardGate();
    st0.guardGate();

    std::cout << std::endl;

    std::cout << "Name: " << st0.getName() << std::endl;
    std::cout << "Hit points: " << st0.getHitPoints() << std::endl;
    std::cout << "Energy points: " << st0.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << st0.getAttackDamage() << std::endl;

    std::cout << std::endl;
}