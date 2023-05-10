#include "Array.hpp"
#include <iostream>
#define INT_SIZE 10

template <class T>
static std::ostream &operator<<(std::ostream &os, const Array<T> &arr) {
    os << '{';
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i != 0)
            os << ", ";
        os << arr[i];
    }
    os << '}';
    return os;
}

int main() {
    Array<int> empty;
    std::cout << empty << std::endl;

    Array<int> ints(INT_SIZE);
    std::cout << ints << std::endl;
    srand(time(NULL));
    for (int i = 0; i < INT_SIZE; ++i)
        ints[i] = rand() % 10;
    std::cout << ints << std::endl;

    try {
        ints[-1] = 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        ints[INT_SIZE] = 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    Array<std::string> s1(3);
    s1[1] = "yolowesh";
    std::cout << s1 << std::endl;

    Array<std::string> s2 = s1;
    s2[0] = "Le temps est l'image mobile de la realite immobile.";
    s2[2] = "Pierre qui roule n'amasse pas mousse.";
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
}