#pragma once

#include <string>

class Date {
public:
	Date();
	explicit Date(const std::string& s);
	Date& operator=(const Date& other);
	Date(const Date& other);
	~Date();

	bool operator==(const Date& other) const;
	bool operator!=(const Date& other) const;
	bool operator>(const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator<(const Date& other) const;
	bool operator<=(const Date& other) const;

	int getYear() const;
	int getMonth() const;
	int getDay() const;

	bool isLeap() const;
	bool isValid() const;

	std::string toString() const;

private:
	int _year;
	int _month;
	int _day;
};

std::ostream& operator<<(std::ostream& os, const Date& date);