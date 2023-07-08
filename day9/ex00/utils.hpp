#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/stat.h>

#define SPACES " \f\n\r\t\v"

bool complain(const std::string& message);
bool parseDouble(const std::string& s, double& out);
bool readFile(const char* path, std::stringstream& content);
std::string strtrim(const std::string& s);