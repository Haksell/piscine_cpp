#include "Zombie.hpp"
#define HORDE_SIZE 7

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " name" << std::endl;
        return EXIT_FAILURE;
    }
    Zombie *horde = zombieHorde(HORDE_SIZE, argv[1]);
    for (int i = 0; i < HORDE_SIZE; ++i)
        horde[i].announce();
    delete[] horde;
}