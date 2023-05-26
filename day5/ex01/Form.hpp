#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
private:
	Form();
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;

public:
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form& form);
	Form& operator=(const Form& form);
	~Form();

	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);
