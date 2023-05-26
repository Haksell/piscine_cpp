#include "ex02.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	checkRequirements(executor);
	std::cout
		<< "PRESIDENTIAL PARDON\n\nFROM: President Zaphod Beeblebrox\nPresident of the "
		   "Galaxy\n\nTO: "
		<< _target << "\n\nDATE: 26th May 2023\n\nDear " << _target
		<< ",\n\nUpon careful and thorough "
		   "review of the circumstances surrounding your case, and the powers vested in me as the "
		   "President of the Galaxy, I, Zaphod Beeblebrox, hereby grant you a full and "
		   "unconditional pardon for all offenses against the laws of the Galaxy you have been "
		   "accused or convicted of.\n\nIn doing so, I do not seek to undermine the important "
		   "processes and functions of our justice system but rather to ensure that it acts as a "
		   "force of fairness, justice, and mercy. It is with great empathy and understanding for "
		   "your situation that I have come to this decision. This is a recognition that people "
		   "can change, make amends, and contribute positively to society, and that justice also "
		   "involves mercy and compassion.\n\nPlease take this pardon as an opportunity to lead a "
		   "life of uprightness and service to the galaxy and its inhabitants. May your actions "
		   "henceforth reflect the mercy shown to you on this day.\n\nYour path forward is now "
		   "unobstructed by the shadows of your past. May you walk it with newfound wisdom, "
		   "integrity, and a deep respect for the laws that bind our diverse galaxy "
		   "together.\n\nSigned,\n\nZaphod Beeblebrox\nPresident of the Galaxy\n";
}
