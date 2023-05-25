#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm_" + target, ShrubberyCreationForm::defaultSignGrade,
			ShrubberyCreationForm::defaultExecuteGrade) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& form)
	: AForm(form.getName(), form.getSignGrade(), form.getExecuteGrade()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget(void) const { return this->target; }

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	std::cout << executor.getName() << " executed " << this->getName() << ".\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
	if (this != &form) {
		this->AForm::operator=(form);
		*const_cast<std::string*>(&this->target) = form.target;
	}
	return *this;
}

AForm::~AForm() {}
