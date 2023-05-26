#include "ScalarConverter.hpp"

static void display_title(std::string s) {
	std::cout << BOLDBLUE << "--- " << s << " ---" << RESET << std::endl;
}

static void section(std::string title, std::vector<std::string> strings) {
	display_title(title);
	std::cout << std::endl;
	for (size_t i = 0; i < strings.size(); ++i) {
		std::cout << GREEN << "string: \"" << strings[i] << '"' << RESET << std::endl;
		ScalarConverter::convert(strings[i]);
		std::cout << std::endl;
	}
}

static void test() {
	std::string s[] = {"inf", "-inf", "+inf", "nan", "inff", "-inff", "+inff", "nanf", "nope"};
	section("SPECIAL VALUES", std::vector<std::string>(s, s + sizeof(s) / sizeof(std::string)));

	std::string c[] = {"' '", "'*'", "'0'", "'A'", "'z'", "'~'", "'è'"};
	section("CHARACTERS", std::vector<std::string>(c, c + sizeof(c) / sizeof(std::string)));

	std::string i[] = {"-2147483649", "-2147483648", "-1",			"0",
					   "1",			  "42",			 "+2147483647", "2147483648"};
	section("INTEGERS", std::vector<std::string>(i, i + sizeof(i) / sizeof(std::string)));

	std::string f[] = {"-340282346638528859811704183484516925440.0f", "-42.0f", "1.1f",
					   "0.000000000001f",
					   "99999999999999999999999999999999999999999999999999999999999999.0f"};
	section("FLOATS", std::vector<std::string>(f, f + sizeof(f) / sizeof(std::string)));

	std::string d[] = {"-340282346638528859811704183484516925440.0", "-42.0", "1.1",
					   "+0.000000000001",
					   "99999999999999999999999999999999999999999999999999999999999999.0"};
	section("DOUBLES", std::vector<std::string>(d, d + sizeof(d) / sizeof(std::string)));
}

int main(int argc, char** argv) {
	if (argc == 1) {
		test();
		return EXIT_SUCCESS;
	} else if (argc == 2) {
		ScalarConverter::convert(argv[1]);
		return EXIT_SUCCESS;
	} else {
		std::cerr << "Usage: " << argv[0] << " (<char>|<int>|<float>|<double>)?\n";
		std::cerr << "Examples:\n";
		std::cerr << "- " << argv[0] << std::endl;
		std::cerr << "- " << argv[0] << " \"'Z'\"\n";
		std::cerr << "- " << argv[0] << " -42\n";
		std::cerr << "- " << argv[0] << " 3.14f\n";
		std::cerr << "- " << argv[0] << " -12.34567\n";
		std::cerr << "- " << argv[0] << " -inff\n";
		return EXIT_FAILURE;
	}
}
