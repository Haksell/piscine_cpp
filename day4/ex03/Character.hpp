#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
// #define CHARACTER_SLOTS 4

class Character : public ICharacter {
public:
	Character();
	Character(const std::string& name);
	Character(const Character& character);
	Character& operator=(const Character& character);
	~Character();

	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	const std::string stringify() const;

private:
	const static int numSlots = 4;
	std::string name;
	AMateria* slots[Character::numSlots];
};

std::ostream& operator<<(std::ostream& os, Character const& character);

#endif