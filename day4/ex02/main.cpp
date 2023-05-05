#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"
#define NUM_ANIMALS 4

static void display_title(std::string title) {
    std::cout << BOLDBLUE << "--- " << title << " ---\n" << RESET;
}

int main() {
    // display_title("PURE AANIMAL");
    // AAnimal *aanimal = new AAnimal();
    // delete aanimal;
    display_title("DEFAULT CONSTRUCTORS");
    AAnimal *animals[NUM_ANIMALS] = {new Dog(), new Dog(), new Cat(),
                                     new Cat()};
    display_title("AANIMAL INFO");
    for (int i = 0; i < NUM_ANIMALS; ++i) {
        std::cout << "i: " << i << " type: " << animals[i]->getType()
                  << " sound: ";
        animals[i]->makeSound();
    }
    display_title("DEEP COPY");
    Dog dog1;
    std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
    dog1.setIdea(0, "Qui vole un oeuf vole un boeuf.");
    std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
    Dog dog2(dog1);
    std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
    dog2.setIdea(0, "Pas de bras, pas de chocolat.");
    std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
    std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
    dog2 = dog1;
    std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
    dog2.setIdea(0, "Le temps est l'image mobile de la realite immobile.");
    std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
    std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
    display_title("DESTRUCTORS");
    for (int i = 0; i < NUM_ANIMALS; ++i)
        delete animals[i];
}