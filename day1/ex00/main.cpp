#include "Zombie.hpp"

int main() {
    Zombie *weirdo = newZombie("imapointerforsomereason");
    weirdo->announce();
    Zombie haksell = Zombie("Haksell");
    haksell.announce();
    haksell.announce();
    haksell.announce();
    delete weirdo;
    randomChump("wololo");
}