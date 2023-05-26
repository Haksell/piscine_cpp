#include "ex03.hpp"

int main() {
	Bureaucrat shrike("The Shrike", 1);
	Intern someRandomIntern;
	AForm* form;

	form = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	form->beSigned(shrike);
	form->execute(shrike);
	delete form;

	try {
		form = someRandomIntern.makeForm("TeleportationReportForm", "Steve");
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
