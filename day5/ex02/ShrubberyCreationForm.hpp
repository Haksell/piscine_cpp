#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &form);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);
    ~ShrubberyCreationForm();

    std::string getTarget(void) const;
    void execute(Bureaucrat const &executor) const;

  private:
    ShrubberyCreationForm();
    const std::string target;
    static const int defaultSignGrade = 145;
    static const int defaultExecuteGrade = 137;
};
