#pragma once

#include "ex02.hpp"

class AForm {
private:
	AForm();
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;

protected:
	const std::string _target;
	void checkRequirements(const Bureaucrat& bureaucrat) const;

public:
	AForm(const std::string& name, const std::string& target, int signGrade, int executeGrade);
	AForm(const AForm& form);
	AForm& operator=(const AForm& form);
	virtual ~AForm();

	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
