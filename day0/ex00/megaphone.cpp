#include <cstring>
#include <iostream>

void shout(char *s) {
    const int length = strlen(s);
    for (int i = 0; i < length; ++i)
        std::cout << static_cast<char>(toupper(s[i]));
}

int main(int argc, char **argv) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        for (int i = 1; i < argc; ++i)
            shout(argv[i]);
    std::cout << std::endl;
}