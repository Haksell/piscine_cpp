#include "Bureaucrat.hpp"

const std::string Bureaucrat::defaultName = "Jean-Luc Melenchon";

void Bureaucrat::assignGrade(int grade) {
	if (grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat() : name(defaultName), grade(lowestGrade) {}

Bureaucrat::Bureaucrat(int grade) : name(defaultName) { this->assignGrade(grade); }

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(lowestGrade) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) { this->assignGrade(grade); }

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
	: name(bureaucrat.name), grade(bureaucrat.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	if (this != &bureaucrat)
		this->grade = bureaucrat.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
	if (this->grade == Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	--this->grade;
}

void Bureaucrat::decrementGrade() {
	if (this->grade == Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	++this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}