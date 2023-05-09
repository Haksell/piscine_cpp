#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

static bool convertSpecial(const std::string &input, std::string *special) {
    const bool isSpecialDouble =
        input == "inf" || input == "-inf" || input == "nan";
    const bool isSpecialFloat =
        input == "inff" || input == "-inff" || input == "nanf";
    if (isSpecialDouble || isSpecialFloat) {
        *special = input;
        if (isSpecialFloat) {
            (*special).resize(special->size() - 1);
        }
        return true;
    }
    return false;
}

static bool convertChar(const std::string &input, t_num *num) {
    if (input.size() == 3 && input[0] == '\'' && input[2] == '\'') {
        num->c = input[1];
        num->n = num->c;
        return true;
    }
    return false;
}

static bool convertNum(const std::string &input, t_num *num) {
    if (input == "." || input == ".f" || input == "-." || input == "-.f")
        return false;
    int sign = 1;
    bool dotFound = false;
    double decimal = 0.1;
    num->c = num->n = num->f = num->d = 0;
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
        } else if (c == 'f') {
            if (i == input.size() - 1)
                num->d = float(num->d);
            else
                return false;
        } else if (isdigit(c)) {
            int digit = c - '0';
            if (dotFound) {
                num->d += decimal * digit;
                decimal *= 0.1;
            } else {
                num->d = 10 * num->d + digit;
            }
        } else {
            return false;
        }
    }
    num->d *= sign;
    if (!std::isfinite(num->d))
        return false;
    if (num->d > INT_MAX || num->d < INT_MIN || fmod(num->d, 1) != 0) {

    } else {
        num->isValidChar = num->isValidInt = false;
    }

    return std::isfinite(num->d);
}

void ScalarConverter::convert(const std::string &input) {
    std::string special;
    t_num num;

    float f = 42.123456789123456789f;
    double d = 4.9406564584124654E-324;
    std::cout << std::setprecision(999999);
    std::cout << f << std::endl;
    std::cout << d << std::endl;

    if (convertSpecial(input, &special)) {
        std::cout << "char: " << NO;
        std::cout << "int: " << NO;
        std::cout << "float: " << special << 'f' << std::endl;
        std::cout << "double: " << special << std::endl;
    } else if (convertChar(input, &num)) {
        std::cout << "char: " << num.c << std::endl;
        std::cout << "int: " << num.n << std::endl;
        std::cout << "float: " << num.n << ".0f" << std::endl;
        std::cout << "double: " << num.n << ".0" << std::endl;
    } else if (convertNum(input, &num)) {
        if (num.isValidChar)
            std::cout << "char: " << num.c << std::endl;
        else
            std::cout << "char: " << NO;
        if (num.isValidInt)
            std::cout << "int: " << num.n << std::endl;
        else
            std::cout << "int: " << NO;
        if (num.isValidFloat)
            std::cout << "float: " << num.f << std::endl;
        else
            std::cout << "float: " << NO;
        std::cout << "double: " << num.d << std::endl;
    } else {
        std::cout << "Invalid conversion" << std::endl;
    }
}
