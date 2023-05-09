#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " (char|int|float|double)\n";
        std::cerr << "Examples:\n";
        std::cerr << "- " << argv[0] << " 'Z'\n";
        std::cerr << "- " << argv[0] << " '-42'\n";
        std::cerr << "- " << argv[0] << " '3.14f'\n";
        std::cerr << "- " << argv[0] << " '-12.34567'\n";
        std::cerr
            << "Other special values are: inf, -inf, nan, -inff, inff, nanf.\n";
        return EXIT_FAILURE;
    }
    ScalarConverter::convert(argv[1]);
}
