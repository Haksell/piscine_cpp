#include "Intern.hpp"
#include "ex03.hpp"

Intern::Intern() {}
Intern::~Intern() {}

static AForm* newRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* newPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

static AForm* newShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) {
	std::pair<std::string, FormCreator> pairs[] = {
		std::make_pair("RobotomyRequestForm", &newRobotomyRequestForm),
		std::make_pair("PresidentialPardonForm", &newPresidentialPardonForm),
		std::make_pair("ShrubberyCreationForm", &newShrubberyCreationForm),
	};
	size_t size = sizeof(pairs) / sizeof(*pairs);
	for (size_t i = 0; i < size; ++i) {
		if (form == pairs[i].first)
			return pairs[i].second(target);
	}
	throw Intern::UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() { return "Form is unknown"; }
