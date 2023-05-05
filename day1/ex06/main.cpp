#include "Harl.hpp"

size_t getIndex(std::vector<std::string> levels, std::string level) {
    for (size_t i = 0; i < levels.size(); ++i)
        if (levels[i] == level)
            return i;
    return levels.size();
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " (DEBUG|INFO|WARNING|ERROR)\n";
        return EXIT_FAILURE;
    }
    std::string level(argv[1]);
    std::vector<std::string> levels;
    levels.push_back("DEBUG");
    levels.push_back("INFO");
    levels.push_back("WARNING");
    levels.push_back("ERROR");
    const size_t i = getIndex(levels, level);
    if (i == levels.size()) {
        std::cerr << "Unknown level: " << level << std::endl;
        return EXIT_FAILURE;
    }
    Harl harl;
    switch (i) {
    case 0:
        harl.complain(levels[0]);
    case 1:
        harl.complain(levels[1]);
    case 2:
        harl.complain(levels[2]);
    case 3:
        harl.complain(levels[3]);
    }
}