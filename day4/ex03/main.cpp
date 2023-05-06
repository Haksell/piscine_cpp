#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"

static void display_title(std::string title) {
    std::cout << BOLDBLUE << "--- " << title << " ---\n" << RESET;
}

static void subjectMain() {
    display_title("SUBJECT MAIN");
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}

static void fullMain() {
    display_title("OVERFLOWED MATERIASOURCE");
    MateriaSource *src = new MateriaSource();
    std::cout << *src;
    src->learnMateria(new Ice());
    src->learnMateria(NULL);
    src->learnMateria(new Cure());
    std::cout << *src;
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    std::cout << *src;

    display_title("USE");
    Character *axel = new Character("axel");
    Character *bob = new Character("bob");
    AMateria *tmp1;
    AMateria *tmp2;
    AMateria *tmp3;
    tmp1 = src->createMateria("ice");
    axel->equip(tmp1);
    tmp2 = src->createMateria("cure");
    axel->equip(tmp2);
    tmp1 = src->createMateria("fire");
    axel->equip(tmp1);
    axel->use(-1, *bob);
    axel->use(0, *bob);
    axel->use(1, *bob);
    axel->use(2, *bob);
    axel->use(4, *bob);
    std::cout << *axel;
    std::cout << *bob;

    display_title("DEEP COPY CHARACTER");
    Character *danil = new Character("danil");
    tmp3 = src->createMateria("cure");
    danil->equip(tmp3);
    danil->equip(src->createMateria("ice"));
    danil->equip(src->createMateria("earth"));
    Character *danil_copy = new Character(*danil);
    danil->unequip(0);
    danil_copy->equip(src->createMateria("cure"));
    danil_copy->equip(src->createMateria("ice"));
    danil->use(0, *bob);
    danil->use(1, *bob);
    danil->use(2, *bob);
    danil->use(3, *bob);
    danil_copy->use(0, *bob);
    danil_copy->use(1, *bob);
    danil_copy->use(2, *bob);
    danil_copy->use(3, *bob);

    display_title("GOODBYE");
    axel->unequip(1);
    axel->use(1, *danil);

    delete bob;
    delete axel;
    delete src;
    delete danil;
    delete danil_copy;
    delete tmp2;
    delete tmp3;
}

int main() {
    subjectMain();
    fullMain();
}