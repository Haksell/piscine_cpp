#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
private:
	AForm();
	const std::string name;
	const int signGrade;
	const int executeGrade;
	bool isSigned;

public:
	AForm(std::string name, int signGrade, int executeGrade);
	AForm(const AForm& form);
	AForm& operator=(const AForm& form);
	~AForm();

	const std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	int getIsSigned() const;

	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
