#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>

static std::string getUser() {
    char *user = getenv("USER");
    return user ? user : "Anonymous";
}

int main() {
    Bureaucrat zaphod("Zaphod", 1);
    Bureaucrat user(getUser(), 42);
    Bureaucrat spartacus("Spartacus", 150);
    Form nuclearStrike("NuclearStrike", 1, 1);
    Form takeTheGarbageOut("TakeTheGarbageOut", 140, 140);

    try {
        Form impossible("Impossible", 0, 30);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    zaphod.signForm(nuclearStrike);
    try {
        user.signForm(nuclearStrike);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        spartacus.signForm(nuclearStrike);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        spartacus.signForm(takeTheGarbageOut);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    nuclearStrike.beSigned(zaphod);
    takeTheGarbageOut.beSigned(zaphod);
    try {
        nuclearStrike.beSigned(user);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    takeTheGarbageOut.beSigned(user);
    try {
        nuclearStrike.beSigned(spartacus);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        takeTheGarbageOut.beSigned(spartacus);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
