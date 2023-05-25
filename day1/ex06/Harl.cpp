#include "Harl.hpp"

Harl::Harl() {
	logFunctions["DEBUG"] = &Harl::debug;
	logFunctions["INFO"] = &Harl::info;
	logFunctions["WARNING"] = &Harl::warning;
	logFunctions["ERROR"] = &Harl::error;
}

void Harl::debug() { std::cout << DEBUG << std::endl; }
void Harl::info() { std::cout << INFO << std::endl; }
void Harl::warning() { std::cout << WARNING << std::endl; }
void Harl::error() { std::cout << ERROR << std::endl; }

void Harl::complain(std::string level) {
	log_map_t::iterator func = logFunctions.find(level);

	if (func == logFunctions.end())
		std::cout << UNKNOWN << std::endl;
	else
		(this->*(func->second))();
}
