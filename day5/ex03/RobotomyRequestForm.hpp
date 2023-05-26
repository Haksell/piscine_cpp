#pragma once

#include "ex03.hpp"

class RobotomyRequestForm : public AForm {
private:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& rrf);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rrf);

public:
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	void execute(const Bureaucrat& executor) const;
};
