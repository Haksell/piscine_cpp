#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade)
	: name(name), signGrade(signGrade), executeGrade(executeGrade), isSigned(false) {
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& form)
	: name(form.name), signGrade(form.signGrade), executeGrade(form.executeGrade),
	  isSigned(form.isSigned) {}

AForm& AForm::operator=(const AForm& form) {
	if (this != &form) {
		*const_cast<std::string*>(&this->name) = form.name;
		*const_cast<int*>(&this->signGrade) = form.signGrade;
		*const_cast<int*>(&this->executeGrade) = form.executeGrade;
		this->isSigned = form.isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const { return this->name; }
int AForm::getSignGrade() const { return this->signGrade; }
int AForm::getExecuteGrade() const { return this->executeGrade; }
int AForm::getIsSigned() const { return this->isSigned; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	else if (this->isSigned)
		std::cout << bureaucrat.getName() << " could not sign " << this->getName()
				  << " because it is already signed.\n";
	else {
		std::cout << bureaucrat.getName() << " signed " << this->getName() << ".\n";
		this->isSigned = true;
	}
}

const char* AForm::GradeTooHighException::what() const throw() { return "Form grade too high"; }

const char* AForm::GradeTooLowException::what() const throw() { return "Form grade too low"; }

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form " << form.getName() << " is signable by grade " << form.getSignGrade()
	   << " and executable by grade " << form.getExecuteGrade() << ". It is"
	   << (form.getIsSigned() ? " " : " not yet ") << "signed.\n";
	return os;
}