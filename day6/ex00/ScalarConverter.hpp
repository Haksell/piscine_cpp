#pragma once

#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

#define NO "❌❌❌\n"

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