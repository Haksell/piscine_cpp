#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string Bureaucrat::defaultName = "Jean-Luc Melenchon";

Bureaucrat::Bureaucrat() : _name(defaultName), _grade(lowestGrade) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
	: _name(bureaucrat._name), _grade(bureaucrat._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	if (this != &bureaucrat) {
		_grade = bureaucrat._grade;
		*const_cast<std::string*>(&_name) = bureaucrat._name;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::signForm(Form& form) {
	if (_grade > form.getSignGrade()) {
		std::cout << _name << " could not sign " << this->getName()
				  << " because their grade is too low.\n";
	} else {
		form.beSigned(*this);
	}
}

void Bureaucrat::incrementGrade() {
	if (_grade == Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade == Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return os;
}