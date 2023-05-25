#include <iostream>
#include <string>

int main() {
	std::string s = "HI THIS IS BRAIN";
	std::string* stringPTR = &s;
	std::string& stringREF = s;
	std::cout << "Address of s: " << &s << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address in stringREF: " << &stringREF << std::endl;
	std::cout << "Value of s: " << s << std::endl;
	std::cout << "Value in stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value in stringREF: " << stringREF << std::endl;
}