#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

static bool isPrintable(char c) { return 32 <= c && c <= 126; }

static bool convertSpecial(const std::string& input, std::string* special) {
	const bool isSpecialDouble =
		input == "inf" || input == "-inf" || input == "+inf" || input == "nan";
	const bool isSpecialFloat =
		input == "inff" || input == "-inff" || input == "+inff" || input == "nanf";
	if (isSpecialDouble || isSpecialFloat) {
		*special = input;
		if (isSpecialFloat) {
			(*special).resize(special->size() - 1);
		}
		return true;
	}
	return false;
}

static bool convertChar(const std::string& input, t_num* num) {
	if (input.size() == 3 && input[0] == '\'' && isPrintable(input[1]) && input[2] == '\'') {
		num->c = input[1];
		num->n = static_cast<int>(num->c);
		num->f = static_cast<float>(num->c);
		num->d = static_cast<double>(num->c);
		return true;
	}
	return false;
}

static bool convertNum(const std::string& input, t_num* num) {
	// TODO ignore more stuff like "+" "+." "f" and more
	if (input == "." || input == ".f" || input == "-." || input == "-.f")
		return false;
	int sign = 1;
	bool dotFound = false;
	double decimal = 0.1;
	num->d = 0;
	for (size_t i = 0; i < input.size(); ++i) {
		char c = input[i];
		if (c == '.') {
			if (dotFound)
				return false;
			dotFound = true;
		} else if (c == '-') {
			if (i == 0)
				sign = -1;
			else
				return false;
		} else if (c == '+') {
			if (i != 0)
				return false;
		} else if (c == 'f') {
			if (i == input.size() - 1)
				num->d = static_cast<float>(num->d);
			else
				return false;
		} else if (isdigit(c)) {
			int digit = c - '0';
			if (dotFound) {
				num->d += decimal * digit;
				decimal *= 0.1;
			} else
				num->d = 10 * num->d + digit;
		} else
			return false;
	}
	num->d *= sign;
	if (!std::isfinite(num->d))
		return false;
	if (std::numeric_limits<int>::min() <= num->d && num->d <= std::numeric_limits<int>::max() &&
		fmod(num->d, 1) == 0) {
		num->isValidInt = true;
		num->n = static_cast<int>(num->d);
		if (isPrintable(num->n)) {
			num->isValidChar = true;
			num->c = static_cast<char>(num->n);
		} else
			num->isValidChar = false;
	} else {
		num->isValidChar = num->isValidInt = false;
	}
	if (-std::numeric_limits<float>::max() <= num->d &&
		num->d <= std::numeric_limits<float>::max()) {
		num->f = static_cast<float>(num->d);
		num->isValidFloat = true;
	} else
		num->isValidFloat = false;
	return std::isfinite(num->d);
}

static std::string formatDouble(double d) {
	std::stringstream ss;
	ss << std::fixed << std::setprecision(999) << d;
	std::string str = ss.str();
	if (str.find('.') != std::string::npos) {
		str = str.substr(0, str.find_last_not_of('0') + 1);
		if (str.find('.') == str.size() - 1)
			str += '0';
	}
	return str;
}

void ScalarConverter::convert(const std::string& input) {
	std::string special;
	t_num num;

	if (convertSpecial(input, &special)) {
		std::cout << "  char: " << NO;
		std::cout << "   int: " << NO;
		std::cout << " float: " << special << 'f' << std::endl;
		std::cout << "double: " << special << std::endl;
	} else if (convertChar(input, &num)) {
		std::cout << "  char: " << num.c << std::endl;
		std::cout << "   int: " << num.n << std::endl;
		std::cout << " float: " << num.f << ".0f" << std::endl;
		std::cout << "double: " << num.d << ".0" << std::endl;
	} else if (convertNum(input, &num)) {
		if (num.isValidChar)
			std::cout << "  char: " << num.c << std::endl;
		else
			std::cout << "  char: " << NO;
		if (num.isValidInt)
			std::cout << "   int: " << num.n << std::endl;
		else
			std::cout << "   int: " << NO;
		if (num.isValidFloat)
			std::cout << " float: " << formatDouble(num.f) << 'f' << std::endl;
		else
			std::cout << " float: " << NO;
		std::cout << "double: " << formatDouble(num.d) << std::endl;
	} else {
		std::cout << "Invalid conversion" << std::endl;
	}
}
