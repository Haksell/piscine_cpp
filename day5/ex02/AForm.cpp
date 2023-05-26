#include "ex02.hpp"

AForm::AForm(const std::string& name, const std::string& target, int signGrade, int executeGrade)
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false),
	  _target(target) {
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& form)
	: _name(form._name), _signGrade(form._signGrade), _executeGrade(form._executeGrade),
	  _isSigned(form._isSigned) {}

AForm& AForm::operator=(const AForm& form) {
	if (this != &form) {
		*const_cast<std::string*>(&this->_name) = form._name;
		*const_cast<int*>(&this->_signGrade) = form._signGrade;
		*const_cast<int*>(&this->_executeGrade) = form._executeGrade;
		this->_isSigned = form._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecuteGrade() const { return _executeGrade; }
bool AForm::isSigned() const { return _isSigned; }

void AForm::checkRequirements(const Bureaucrat& bureaucrat) const {
	if (!_isSigned)
		throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > _executeGrade)
		throw Bureaucrat::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	std::cout << ORANGE;
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else if (_isSigned)
		std::cout << bureaucrat.getName() << " could not sign " << _name
				  << " because it is already signed.\n";
	else {
		std::cout << bureaucrat.getName() << " signed " << _name << ".\n";
		_isSigned = true;
	}
	std::cout << RESET;
}

void AForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > _executeGrade)
		throw AForm::NotSignedException();
}

const char* AForm::GradeTooHighException::what() const throw() { return "Form grade too high"; }

const char* AForm::GradeTooLowException::what() const throw() { return "Form grade too low"; }

const char* AForm::NotSignedException::what() const throw() { return "Form is not signed"; }

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << form.getName() << " is signable by grade " << form.getSignGrade()
	   << " and executable by grade " << form.getExecuteGrade() << ". It is"
	   << (form.isSigned() ? " " : " not yet ") << "signed.\n";
	return os;
}