#include "PhoneBook.hpp"

bool PhoneBook::is_valid_index(std::string str_index, int* num_index) {
	if (str_index == "")
		return false;
	*num_index = 0;
	for (size_t i = 0; i < str_index.size(); ++i) {
		if (!isdigit(str_index[i]))
			return false;
		*num_index = 10 * *num_index + str_index[i] - '0';
		if ((size_t)*num_index >= this->contacts.size())
			return false;
	}
	return true;
}

void PhoneBook::display_column(std::string s) {
	if (s.size() > this->column_width)
		s = s.substr(0, this->column_width - 1) + '.';
	std::cout << " | ";
	std::cout << std::right << std::setw(this->column_width) << s;
}

void PhoneBook::add(Contact contact) {
	if (this->contacts.size() == this->max_users)
		this->contacts.pop_front();
	this->contacts.push_back(contact);
}

void PhoneBook::display_all() {
	for (size_t i = 0; i < this->contacts.size(); ++i) {
		Contact contact = this->contacts[i];
		std::cout << std::right << std::setw(this->column_width) << i;
		display_column(contact.first_name);
		display_column(contact.last_name);
		display_column(contact.nick_name);
		std::cout << std::endl;
	}
}

void PhoneBook::display_one(std::string str_index) {
	int num_index;
	if (is_valid_index(str_index, &num_index)) {
		Contact c = this->contacts[num_index];
		std::cout << "first_name: " << c.first_name << std::endl;
		std::cout << "last_name: " << c.last_name << std::endl;
		std::cout << "nick_name: " << c.nick_name << std::endl;
		std::cout << "phone_number: " << c.phone_number << std::endl;
		std::cout << "darkest_secret: " << c.darkest_secret << std::endl;
	} else
		std::cerr << "Invalid index." << std::endl;
}