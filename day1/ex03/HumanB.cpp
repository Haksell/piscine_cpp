#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL){};

void HumanB::attack() {
	std::string type = this->weapon == NULL ? "inexistent weapon" : this->weapon->getType();
	std::cout << this->name << " attacks with their " << type << std::endl;
};

void HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; };