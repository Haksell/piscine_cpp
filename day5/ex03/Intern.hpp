#pragma once

#include "ex03.hpp"

class Intern {
private:
	Intern(const Intern& form);
	Intern& operator=(const Intern& form);

public:
	Intern();
	~Intern();

	AForm* makeForm(const std::string& form, const std::string& target);

	class UnknownFormException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

typedef AForm* (*FormCreator)(const std::string&);