#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signGrade, int executeGrade)
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false) {
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw Form::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& form)
	: _name(form._name), _signGrade(form._signGrade), _executeGrade(form._executeGrade),
	  _isSigned(form._isSigned) {}

Form& Form::operator=(const Form& form) {
	if (this != &form) {
		*const_cast<std::string*>(&this->_name) = form._name;
		*const_cast<int*>(&this->_signGrade) = form._signGrade;
		*const_cast<int*>(&this->_executeGrade) = form._executeGrade;
		this->_isSigned = form._isSigned;
	}
	return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecuteGrade() const { return _executeGrade; }
bool Form::isSigned() const { return _isSigned; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else if (_isSigned)
		std::cout << bureaucrat.getName() << " could not sign " << _name
				  << " because it is already signed.\n";
	else {
		std::cout << bureaucrat.getName() << " signed " << _name << ".\n";
		_isSigned = true;
	}
}

const char* Form::GradeTooHighException::what() const throw() { return "Form grade too high"; }

const char* Form::GradeTooLowException::what() const throw() { return "Form grade too low"; }

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form " << form.getName() << " is signable by grade " << form.getSignGrade()
	   << " and executable by grade " << form.getExecuteGrade() << ". It is"
	   << (form.isSigned() ? " " : " not yet ") << "signed.\n";
	return os;
}