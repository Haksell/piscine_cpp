#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <deque>
#include <iomanip>
#include <iostream>

class PhoneBook {
  private:
    static const int max_users = 8;
    static const int column_width = 10;
    std::deque<Contact> contacts;
    bool is_valid_index(std::string str_index, int *num_index);
    void display_column(std::string s);

  public:
    void add(Contact contact);
    void display_all();
    void display_one(std::string str_index);
};

#endif