#pragma once

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat {
  private:
    static const std::string defaultName;

    const std::string name;
    int grade;

    Bureaucrat();

  public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);
    ~Bureaucrat();

    const std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &form);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    static const int highestGrade;
    static const int lowestGrade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
