#pragma once

#include "ex03.hpp"

#define SHRUBBERY_DIRECTORY "./shrubberies/"

class ShrubberyCreationForm : public AForm {
private:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& scf);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& scf);

public:
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	void execute(const Bureaucrat& executor) const;
};
