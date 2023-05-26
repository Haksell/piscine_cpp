#include "ex02.hpp"

static void formExecutions() {
	Bureaucrat shrike("The Shrike", 1);

	ShrubberyCreationForm scf("form");
	scf.beSigned(shrike);
	scf.execute(shrike);

	RobotomyRequestForm rrf("Valentin");
	rrf.beSigned(shrike);
	rrf.execute(shrike);

	PresidentialPardonForm ppf("Danil");
	ppf.beSigned(shrike);
	ppf.execute(shrike);
}

static void bureaucratExecutions() {
	Bureaucrat shrike("The Shrike", 1);

	ShrubberyCreationForm scf("bureaucrat");
	shrike.signForm(scf);
	shrike.executeForm(scf);

	RobotomyRequestForm rrf("Valentin");
	shrike.signForm(rrf);
	shrike.executeForm(rrf);

	PresidentialPardonForm ppf("Danil");
	shrike.signForm(ppf);
	shrike.executeForm(ppf);
}

static void failedExecutions() {
	Bureaucrat martin("Martin Silenus", 20);
	ShrubberyCreationForm scf("failed");
	PresidentialPardonForm ppf("Lenar Hoyt");

	try {
		scf.execute(martin);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		ppf.beSigned(martin);
		ppf.execute(martin);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

static void separation() {
	std::cout << "\n\n";
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	for (int i = 0; i < size.ws_col; ++i)
		std::cout << "—";
	std::cout << "\n\n\n";
}

int main() {
	formExecutions();
	separation();
	bureaucratExecutions();
	separation();
	failedExecutions();
}
