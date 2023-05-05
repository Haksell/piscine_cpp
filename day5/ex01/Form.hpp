#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
  private:
    Form();
    const std::string name;
    const int signGrade;
    const int executeGrade;
    bool isSigned;

  public:
    Form(std::string name, int signGrade, int executeGrade);
    Form(const Form &form);
    Form &operator=(const Form &form);
    ~Form();

    const std::string getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    int getIsSigned() const;

    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif