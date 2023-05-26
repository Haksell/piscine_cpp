#pragma once

#include "ex03.hpp"

class PresidentialPardonForm : public AForm {
private:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& ppf);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ppf);

public:
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();
	void execute(const Bureaucrat& executor) const;
};
