#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
	Contact(){};
};

#endif