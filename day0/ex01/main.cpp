#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <unistd.h>

static bool prompt(std::string display, std::string *buffer, bool allow_empty) {
    if (isatty(STDIN_FILENO))
        std::cout << display;
    if (!std::getline(std::cin, *buffer))
        return false;
    return allow_empty || *buffer != "";
}

int main() {
    PhoneBook phonebook;
    while (true) {
        std::string line;
        if (!prompt("$ ", &line, true) || line == "EXIT")
            break;
        else if (line == "ADD") {
            Contact contact = Contact();
            if (prompt("first_name> ", &contact.first_name, false) &&
                prompt("last_name> ", &contact.last_name, false) &&
                prompt("nick_name> ", &contact.nick_name, false) &&
                prompt("phone_number> ", &contact.phone_number, false) &&
                prompt("darkest_secret> ", &contact.darkest_secret, false))
                phonebook.add(contact);
            else if (std::cin.eof())
                break;
            else
                std::cerr << "Contact field can't be empty." << std::endl;
        } else if (line == "SEARCH") {
            phonebook.display_all();
            std::string str_index;
            if (!prompt("index> ", &str_index, true))
                break;
            phonebook.display_one(str_index);
        }
    }
    if (isatty(STDIN_FILENO))
        std::cout << "Goodbye." << std::endl;
}