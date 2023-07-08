#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

typedef bool (*operation)(long, long, long&);

static bool opAdd(long n1, long n2, long& result) {
	if (n2 > 0 && n1 > LONG_MAX - n2) {
		std::cout << n1 << " + " << n2 << " will overflow" << std::endl;
		return false;
	}
	if (n2 < 0 && n1 < LONG_MIN - n2) {
		std::cout << n1 << " + " << n2 << " will underflow" << std::endl;
		return false;
	}
	result = n1 + n2;
	return true;
}

static bool opSub(long n1, long n2, long& result) {
	if (n2 < 0 && n1 > LONG_MAX + n2) {
		std::cout << n1 << " - " << n2 << " will overflow" << std::endl;
		return false;
	}
	if (n2 > 0 && n1 < LONG_MIN + n2) {
		std::cout << n1 << " - " << n2 << " will underflow" << std::endl;
		return false;
	}
	result = n1 - n2;
	return true;
}

static bool opMul(long n1, long n2, long& result) {
	if (n1 == 0 || n2 == 0) {
		result = 0;
		return true;
	}
	result = n1 * n2;
	if (result / n2 != n1) {
		const bool positive = n1 > 0 ? n2 > 0 : n2 < 0;
		std::cout << n1 << " * " << n2 << " will " << (positive ? "ov" : "und") << "erflow"
				  << std::endl;
		return false;
	}
	return true;
}

static bool opDiv(long n1, long n2, long& result) {
	if (n2 == 0) {
		std::cout << n1 << " / " << n2 << " is undefined" << std::endl;
		return false;
	}
	result = n1 / n2;
	return true;
}

static void printProblematicCharacter(const std::string& s, size_t i) {
	std::cout << s.substr(0, i) << RED << s[i] << RESET << s.substr(i + 1) << std::endl;
}

static bool evaluate(const std::string& s, long& final) {
	std::stack<long> stack;
	for (size_t i = 0; i < s.size(); ++i) {
		if (isdigit(s[i])) {
			stack.push(s[i] - '0');
		} else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			if (stack.size() < 2) {
				std::cout << "Stack size is " << stack.size()
						  << " when trying to execute a binary operation" << std::endl;
				printProblematicCharacter(s, i);
				return false;
			}
			long n2 = stack.top();
			stack.pop();
			long n1 = stack.top();
			stack.pop();
			long result;
			operation op = s[i] == '+' ? opAdd : s[i] == '-' ? opSub : s[i] == '*' ? opMul : opDiv;
			if (!op(n1, n2, result)) {
				printProblematicCharacter(s, i);
				return false;
			}
			stack.push(result);
		} else if (s[i] != ' ') {
			if (isprint(s[i])) {
				std::cout << "Invalid character: ";
				printProblematicCharacter(s, i);
			} else {
				std::cout << "Non-printable character at index " << i << std::endl;
			}
			return false;
		}
	}
	if (stack.size() == 0) {
		std::cout << "No operation performed." << std::endl;
		return false;
	} else if (stack.size() == 1) {
		final = stack.top();
		return true;
	} else {
		std::cout << "Stack still contains " << stack.size()
				  << " elements but there are no more operations to process" << std::endl;
		return false;
	}
}

static bool check(const std::string& s, bool expectedSuccess, long expectedFinal) {
	long final = 0;
	bool success = evaluate(s, final);
	std::cout << s << " | ";
	if (success) {
		if (!expectedSuccess) {
			std::cout << RED << "KO, expected failure, got " << final << "\n\n" << RESET;
			return false;
		} else if (final != expectedFinal) {
			std::cout << RED << "KO, expected " << expectedFinal << ", got " << final << "\n\n"
					  << RESET;
			return false;
		} else {
			std::cout << GREEN << "OK " << final << "\n" << RESET;
			return true;
		}
	} else {
		if (expectedSuccess) {
			std::cout << RED << "KO, unexpected failure\n\n" << RESET;
			return false;
		} else {
			std::cout << GREEN << "OK failure\n\n" << RESET;
			return true;
		}
	}
}

bool test() {
	bool success = true;
	std::cout << BOLD << BLUE << "--- VALID ---" << RESET << std::endl;
	success &= check("7", true, 7);
	success &= check("5 3 +", true, 8);
	success &= check("1 2 3 4 5 * * * *", true, 120);
	success &= check("8 9 * 9 - 9 - 9 - 4 - 1 +", true, 42);
	success &= check("7 7 * 7 -", true, 42);
	success &= check("1 2 * 2 / 2 * 2 4 - +", true, 0);
	success &=
		check("8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 * * * * * * * * * * * * * * * * * * *", true,
			  1152921504606846976);
	success &=
		check("6 9 * 7 + 9 * 4 + 9 * 0 + 9 * 4 + 9 * 2 + 9 * 8 + 9 * 3 + 9 * 1 + 9 * 7 + 9 * 2 + 9 "
			  "* 1 + 9 * 0 + 9 * 7 + 9 * 8 + 9 * 1 + 9 * 1 + 9 * 8 + 9 * 2 + 9 * 7 +",
			  true, LONG_MAX);
	success &= check(
		"0 6 - 9 * 7 - 9 * 4 - 9 * 0 - 9 * 4 - 9 * 2 - 9 * 8 - 9 * 3 - 9 * 1 - 9 * 7 - 9 * 2 - 9 "
		"* 1 - 9 * 0 - 9 * 7 - 9 * 8 - 9 * 1 - 9 * 1 - 9 * 8 - 9 * 2 - 9 * 8 -",
		true, LONG_MIN);
	std::cout << std::endl << BOLD << BLUE << "--- INVALID ---" << RESET << std::endl;
	success &= check("", false, 0);
	success &= check("   ", false, 0);
	success &= check("(1 + 1)", false, 0);
	success &= check("3\t2\t+", false, 0);
	success &= check("3 ² +", false, 0);
	success &= check("+ 3 5", false, 0);
	success &= check("3 + 5", false, 0);
	success &= check("3 5 7 +", false, 0);
	success &= check("3 5 + +", false, 0);
	success &= check("7 4 2 2 + - /", false, 0);
	success &=
		check("8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 * * * * * * * * * * * * * * * * * * * *",
			  false, 0);
	success &=
		check("6 9 * 7 + 9 * 4 + 9 * 0 + 9 * 4 + 9 * 2 + 9 * 8 + 9 * 3 + 9 * 1 + 9 * 7 + 9 * 2 + 9 "
			  "* 1 + 9 * 0 + 9 * 7 + 9 * 8 + 9 * 1 + 9 * 1 + 9 * 8 + 9 * 2 + 9 * 8 +",
			  false, 0);
	success &= check(
		"0 6 - 9 * 7 - 9 * 4 - 9 * 0 - 9 * 4 - 9 * 2 - 9 * 8 - 9 * 3 - 9 * 1 - 9 * 7 - 9 * 2 - 9 "
		"* 1 - 9 * 0 - 9 * 7 - 9 * 8 - 9 * 1 - 9 * 1 - 9 * 8 - 9 * 2 - 9 * 9 -",
		false, 0);
	return success;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		return test() ? EXIT_SUCCESS : EXIT_FAILURE;
	} else if (argc == 2) {
		long final;
		if (!evaluate(argv[1], final))
			return EXIT_FAILURE;
		std::cout << final << std::endl;
		return EXIT_SUCCESS;
	} else {
		std::cerr << "Usage: " << argv[0] << " \"[-*+/ \\d]+\"" << std::endl;
		std::cerr << "Example: " << argv[0] << " \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return EXIT_FAILURE;
	}
}
