#pragma once

#include "ex03.hpp"

class Bureaucrat {
private:
	static const std::string defaultName;

	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void signForm(AForm& form);
	void executeForm(const AForm& form);

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	static const int highestGrade = 1;
	static const int lowestGrade = 150;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
