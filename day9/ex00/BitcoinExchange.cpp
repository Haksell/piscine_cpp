#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

static bool parseLine(const std::string& line, Date& date, double& value, double maxValue,
					  char separator) {
	std::string dateStr, valueStr;
	std::istringstream iss(line);
	if (!std::getline(iss, dateStr, separator) || !std::getline(iss, valueStr, separator) ||
		!iss.eof())
		return complain("invalid line: " + line);
	dateStr = strtrim(dateStr);
	valueStr = strtrim(valueStr);
	date = Date(dateStr);
	if (!date.isValid())
		return complain("invalid date: " + dateStr);
	if (!parseDouble(valueStr, value))
		return complain("invalid value: " + valueStr);
	if (value < 0)
		return complain("negative value: " + valueStr);
	if (value > maxValue)
		return complain("value too large: " + valueStr);
	return true;
}

bool BitcoinExchange::update(std::stringstream& dataStream) {
	_data.clear();
	std::string line;
	std::getline(dataStream, line);
	if (line != "date,exchange_rate")
		return complain("invalid data header: " + line);
	while (std::getline(dataStream, line)) {
		Date date;
		double value;
		if (!parseLine(line, date, value, 1000000000, ','))
			return false;
		if (_data.find(date) != _data.end())
			return complain("duplicate data date: " + date.toString());
		_data[date] = value;
	}
	return _data.empty() ? complain("no data found in file") : true;
}

bool BitcoinExchange::query(const std::string& line) const {
	Date date;
	double value;
	if (!parseLine(line, date, value, 1000, '|'))
		return false;
	std::map<Date, double>::const_iterator it = _data.lower_bound(date);
	if (it->first != date) {
		if (it == _data.begin())
			return complain("date too old " + date.toString());
		--it;
	}
	std::cout << std::fixed << std::setprecision(2);
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	return true;
}