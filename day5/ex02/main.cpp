#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

static std::string getUser() {
    char *user = getenv("USER");
    return user ? user : "Anonymous";
}

int main() {
    Bureaucrat zaphod("Zaphod", 1);
    Bureaucrat user(getUser(), 42);
    Bureaucrat spartacus("Spartacus", 150);
    AForm nuclearStrike("NuclearStrike", 1, 1);
    AForm takeTheGarbageOut("TakeTheGarbageOut", 140, 140);

    try {
        AForm impossible("Impossible", 0, 30);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    zaphod.signForm(nuclearStrike);
    user.signForm(nuclearStrike);
    spartacus.signForm(nuclearStrike);
    spartacus.signForm(takeTheGarbageOut);

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
