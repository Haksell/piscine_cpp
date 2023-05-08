#include "Bureaucrat.hpp"

const std::string Bureaucrat::defaultName = "Jean-Luc Melenchon";
const int Bureaucrat::highestGrade = 1;
const int Bureaucrat::lowestGrade = 150;

Bureaucrat::Bureaucrat() : name(defaultName), grade(lowestGrade) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade < Bureaucrat::highestGrade)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > Bureaucrat::lowestGrade)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : name(bureaucrat.name), grade(bureaucrat.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat) {
        *const_cast<std::string *>(&this->name) = bureaucrat.name;
        this->grade = bureaucrat.grade;
    }
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

void Bureaucrat::signForm(Form &form) {
    if (this->grade > form.getSignGrade())
        std::cout << this->name << " could not sign " << form.getName()
                  << " because their grade is too low.\n";
    else
        form.beSigned(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
       << std::endl;
    return os;
}