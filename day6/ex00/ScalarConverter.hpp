#pragma once

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#define NO "❌❌❌\n"
#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"
#define GREEN "\033[32m"

typedef struct s_num {
    char c;
    bool isValidChar;
    int n;
    bool isValidInt;
    float f;
    bool isValidFloat;
    double d;
} t_num;

class ScalarConverter {
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &scalarConverter);
    ScalarConverter &operator=(const ScalarConverter &scalarConverter);

  public:
    static void convert(const std::string &input);
    ~ScalarConverter();
};