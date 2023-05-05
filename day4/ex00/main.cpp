#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include <iostream>

void wrong() {
    const WrongAnimal *wrongCat = new WrongCat();
    const WrongAnimal *wrongDog = new WrongDog();
    const WrongAnimal *wrongAnimal = new WrongAnimal();

    std::cout << wrongCat->getType() << ": ";
    wrongCat->makeSound();
    std::cout << wrongDog->getType() << ": ";
    wrongDog->makeSound();
    std::cout << wrongAnimal->getType() << ": ";
    wrongAnimal->makeSound();

    delete wrongAnimal;
    delete wrongCat;
    delete wrongDog;
}

void right() {
    const Animal *cat = new Cat();
    const Animal *dog = new Dog();
    const Animal *animal = new Animal();

    std::cout << cat->getType() << ": ";
    cat->makeSound();
    std::cout << dog->getType() << ": ";
    dog->makeSound();
    std::cout << animal->getType() << ": ";
    animal->makeSound();

    delete animal;
    delete cat;
    delete dog;
}

int main() {
    wrong();
    std::cout << std::endl;
    right();
}