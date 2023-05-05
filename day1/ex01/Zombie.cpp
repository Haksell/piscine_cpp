#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}