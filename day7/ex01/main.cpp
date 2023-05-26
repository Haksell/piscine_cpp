#include "iter.hpp"

int main() {
	int arr1[] = {1, 2, 3, 4, 5};
	iter(arr1, sizeof(arr1) / sizeof(*arr1), print<int>);
	std::cout << std::endl;

	double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(arr2, sizeof(arr2) / sizeof(*arr2), print<double>);
	std::cout << std::endl;

	char arr3[] = {'a', 'b', 'c', 'd', 'e'};
	iter(arr3, sizeof(arr3) / sizeof(*arr3), print<char>);
	std::cout << std::endl;
}