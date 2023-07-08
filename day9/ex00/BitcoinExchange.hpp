#pragma once

#include "Date.hpp"
#include <map>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();

	bool update(std::stringstream& dataStream);
	bool query(const std::string& line) const;

private:
	BitcoinExchange& operator=(const BitcoinExchange& other);
	BitcoinExchange(const BitcoinExchange& other);

	std::map<Date, double> _data;
};
