#pragma once

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <dirent.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#define PPM_PARAM_LIMIT 65535
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define ORANGE "\033[38;5;220m"

class PpmParsingException : public std::runtime_error {
public:
	explicit PpmParsingException() : std::runtime_error("Failed to parse PPM file") {}
	virtual ~PpmParsingException() throw() {}
	virtual const char* what() const throw() { return "Failed to parse PPM file"; }
};

typedef struct PpmParams {
	unsigned int width;
	unsigned int height;
	unsigned int maxval;
} PpmParams;

class AForm;
class Bureaucrat;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
