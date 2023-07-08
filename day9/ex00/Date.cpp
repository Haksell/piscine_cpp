#include "Date.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

Date::Date() : _year(0), _month(0), _day(0) {}

Date::Date(const std::string& s) {
	if (s.size() == 10 && isdigit(s[0]) && isdigit(s[1]) && isdigit(s[2]) && isdigit(s[3]) &&
		s[4] == '-' && isdigit(s[5]) && isdigit(s[6]) && s[7] == '-' && isdigit(s[8]) &&
		isdigit(s[9])) {
		_year = std::atoi(s.c_str() + 0);
		_month = std::atoi(s.c_str() + 5);
		_day = std::atoi(s.c_str() + 8);
	} else {
		_year = _month = _day = 0;
	}
}

Date& Date::operator=(const Date& other) {
	_year = other.getYear();
	_month = other.getMonth();
	_day = other.getDay();
	return *this;
}

Date::Date(const Date& other) { *this = other; }

Date::~Date() {}

bool Date::operator==(const Date& other) const {
	return _year == other.getYear() && _month == other.getMonth() && _day == other.getDay();
}

bool Date::operator!=(const Date& other) const {
	return _year != other.getYear() || _month != other.getMonth() || _day != other.getDay();
}

bool Date::operator>(const Date& other) const {
	if (_year > other.getYear())
		return true;
	if (_year < other.getYear())
		return false;
	if (_month > other.getMonth())
		return true;
	if (_month < other.getMonth())
		return false;
	return _day > other.getDay();
}

bool Date::operator>=(const Date& other) const {
	if (_year > other.getYear())
		return true;
	if (_year < other.getYear())
		return false;
	if (_month > other.getMonth())
		return true;
	if (_month < other.getMonth())
		return false;
	return _day >= other.getDay();
}

bool Date::operator<(const Date& other) const {
	if (_year < other.getYear())
		return true;
	if (_year > other.getYear())
		return false;
	if (_month < other.getMonth())
		return true;
	if (_month > other.getMonth())
		return false;
	return _day < other.getDay();
}

bool Date::operator<=(const Date& other) const {
	if (_year < other.getYear())
		return true;
	if (_year > other.getYear())
		return false;
	if (_month < other.getMonth())
		return true;
	if (_month > other.getMonth())
		return false;
	return _day <= other.getDay();
}

int Date::getYear() const { return _year; }
int Date::getMonth() const { return _month; }
int Date::getDay() const { return _day; }

bool Date::isLeap() const { return _year % 4 == 0 && (_year % 400 == 0 || _year % 100 != 0); }

bool Date::isValid() const {
	if (_year < 1900 || _day <= 0)
		return false;
	switch (_month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return _day <= 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return _day <= 30;
	case 2:
		return _day <= (isLeap() ? 29 : 28);
	default:
		return false;
	};
}

std::string Date::toString() const {
	std::ostringstream os;
	os << std::setfill('0') << std::setw(4) << _year;
	os << '-';
	os << std::setfill('0') << std::setw(2) << _month;
	os << '-';
	os << std::setfill('0') << std::setw(2) << _day;
	return os.str();
}

std::ostream& operator<<(std::ostream& os, const Date& date) { return os << date.toString(); }