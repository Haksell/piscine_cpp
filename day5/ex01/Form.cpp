#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade)
	: name(name), signGrade(signGrade), executeGrade(executeGrade), isSigned(false) {
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw Form::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& form)
	: name(form.name), signGrade(form.signGrade), executeGrade(form.executeGrade),
	  isSigned(form.isSigned) {}

Form& Form::operator=(const Form& form) {
	if (this != &form) {
		*const_cast<std::string*>(&this->name) = form.name;
		*const_cast<int*>(&this->signGrade) = form.signGrade;
		*const_cast<int*>(&this->executeGrade) = form.executeGrade;
		this->isSigned = form.isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string Form::getName() const { return this->name; }
int Form::getSignGrade() const { return this->signGrade; }
int Form::getExecuteGrade() const { return this->executeGrade; }
int Form::getIsSigned() const { return this->isSigned; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	else if (this->isSigned)
		std::cout << bureaucrat.getName() << " could not sign " << this->getName()
				  << " because it is already signed.\n";
	else {
		std::cout << bureaucrat.getName() << " signed " << this->getName() << ".\n";
		this->isSigned = true;
	}
}

const char* Form::GradeTooHighException::what() const throw() { return "Form grade too high"; }

const char* Form::GradeTooLowException::what() const throw() { return "Form grade too low"; }

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form " << form.getName() << " is signable by grade " << form.getSignGrade()
	   << " and executable by grade " << form.getExecuteGrade() << ". It is"
	   << (form.getIsSigned() ? " " : " not yet ") << "signed.\n";
	return os;
}