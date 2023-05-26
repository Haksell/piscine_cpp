#include "ex02.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	checkRequirements(executor);
	std::cout << BLUE << "🤖 Drrrr... 🔩 RAKATAKAKATAKATA 🪓" << RESET << std::endl;
	bool success = std::rand() & 1;
	std::cout << (success ? GREEN : RED) << "Robotomy of " << _target << " was "
			  << (success ? "" : "un") << "successful." << RESET << std::endl;
}