#include "Fixed.hpp"

static void subject_tests() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

static void complete_tests() {
	std::cout << "4.2 > 6.9 : " << (Fixed(4.2f) > Fixed(6.9f)) << std::endl;
	std::cout << "1.1 > 1.1 : " << (Fixed(1.1f) > Fixed(1.1f)) << std::endl;
	std::cout << "13 > 3.4 : " << (Fixed(13) > Fixed(3.4f)) << std::endl;
	std::cout << "4.2 < 6.9 : " << (Fixed(4.2f) < Fixed(6.9f)) << std::endl;
	std::cout << "1.1 < 1.1 : " << (Fixed(1.1f) < Fixed(1.1f)) << std::endl;
	std::cout << "13 < 3.4 : " << (Fixed(13) < Fixed(3.4f)) << std::endl;
	std::cout << "4.2 >= 6.9 : " << (Fixed(4.2f) >= Fixed(6.9f)) << std::endl;
	std::cout << "1.1 >= 1.1 : " << (Fixed(1.1f) >= Fixed(1.1f)) << std::endl;
	std::cout << "13 >= 3.4 : " << (Fixed(13) >= Fixed(3.4f)) << std::endl;
	std::cout << "4.2 <= 6.9 : " << (Fixed(4.2f) <= Fixed(6.9f)) << std::endl;
	std::cout << "1.1 <= 1.1 : " << (Fixed(1.1f) <= Fixed(1.1f)) << std::endl;
	std::cout << "13 <= 3.4 : " << (Fixed(13) <= Fixed(3.4f)) << std::endl;
	std::cout << "4.2 == 6.9 : " << (Fixed(4.2f) == Fixed(6.9f)) << std::endl;
	std::cout << "1.1 == 1.1 : " << (Fixed(1.1f) == Fixed(1.1f)) << std::endl;
	std::cout << "13 == 3.4 : " << (Fixed(13) == Fixed(3.4f)) << std::endl;
	std::cout << "4.2 != 6.9 : " << (Fixed(4.2f) != Fixed(6.9f)) << std::endl;
	std::cout << "1.1 != 1.1 : " << (Fixed(1.1f) != Fixed(1.1f)) << std::endl;
	std::cout << "13 != 3.4 : " << (Fixed(13) != Fixed(3.4f)) << std::endl;
	std::cout << "42 + 1.1 : " << (Fixed(42) + Fixed(1.1f)) << std::endl;
	std::cout << "42 - 1.1 : " << (Fixed(42) - Fixed(1.1f)) << std::endl;
	std::cout << "42 * 1.1 : " << (Fixed(42) * Fixed(1.1f)) << std::endl;
	std::cout << "42 / 1.1 : " << (Fixed(42) / Fixed(1.1f)) << std::endl;
	std::cout << "++4.2 : " << (++Fixed(4.2f)) << std::endl;
	std::cout << "--4.2 : " << (--Fixed(4.2f)) << std::endl;
	std::cout << "4.2++ : " << (Fixed(4.2f)++) << std::endl;
	std::cout << "4.2-- : " << (Fixed(4.2f)--) << std::endl;
	std::cout << "min(4.2, 6.9) : " << (Fixed::min(Fixed(4.2f), Fixed(6.9f))) << std::endl;
	std::cout << "max(4.2, 6.9) : " << (Fixed::max(Fixed(4.2f), Fixed(6.9f))) << std::endl;
}

int main(void) {
	subject_tests();
	std::cout << std::endl;
	complete_tests();
}