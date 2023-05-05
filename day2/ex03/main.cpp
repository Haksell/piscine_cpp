#include "Point.hpp"
#include <iostream>

#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"
#define RED "\033[31m"
#define GREEN "\033[32m"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void display_title(std::string s) {
    std::cout << BOLDBLUE << "--- " << s << " ---" << RESET << std::endl;
}

static void check(Point const a, Point const b, Point const c, Point const o,
                  bool expected) {

    const bool result = bsp(a, b, c, o);
    const std::string color = (result == expected) ? GREEN : RED;
    const std::string verdict = (result == expected) ? "OK" : "KO";
    std::cout << color << o << " in " << a << b << c << ": " << verdict
              << " (expected " << expected << " got " << result << ')' << RESET
              << std::endl;
}

static void test_inside() {
    Point a(0, 0);
    Point b(4, 0);
    Point c(4, 3);

    display_title("INSIDE");
    check(a, b, c, Point(2, 1), true);
    check(a, b, c, Point(3, 1), true);
    check(a, b, c, Point(3, 2), true);
    check(a, b, c, Point(3.9f, 0.1f), true);
    check(a, c, b, Point(2, 1), true);
    check(a, c, b, Point(3, 1), true);
    check(a, c, b, Point(3, 2), true);
    check(a, c, b, Point(3.9f, 0.1f), true);
}

static void test_outside() {
    Point a(0, 0);
    Point b(4, 0);
    Point c(4, 3);

    display_title("OUTSIDE");
    check(a, b, c, Point(2, 2), false);
    check(a, b, c, Point(5, 2), false);
    check(a, b, c, Point(4.1f, 3.1f), false);
}

static void test_edge() {
    Point a(0, 0);
    Point b(4, 0);
    Point c(4, 3);

    display_title("EDGE");
    check(a, b, c, Point(1.0f, 0.75f), false);
    check(a, b, c, Point(2.0f, 1.5f), false);
    check(a, b, c, Point(3, 0), false);
    check(a, b, c, Point(4, 2), false);
}

static void test_corner() {
    Point a(0, 0);
    Point b(4, 0);
    Point c(4, 3);

    display_title("CORNER");
    check(a, b, c, Point(0, 0), false);
    check(a, b, c, Point(4, 0), false);
    check(a, b, c, Point(4, 3), false);
}

static void test_overlapping_triangle() {
    Point a(0, 0);
    Point b(4, 0);
    Point c(4, 3);

    display_title("TWO POINTS TRIANGLE");
    check(a, a, b, Point(2, 0), false);
    check(c, c, b, Point(4, 3), false);
    check(a, a, a, a, false);
}

static void test_linear_triangle() {
    Point a(0, 0);
    Point b(2, 1);
    Point c(4, 2);
    Point d = c; // test copy assignment operator

    display_title("LINEAR TRIANGLE");
    check(a, b, d, Point(1.0f, 0.5f), false);
    check(a, b, d, Point(2, 1), false);
    check(a, b, d, Point(2, 2), false);
}

int main(void) {
    test_inside();
    test_outside();
    test_edge();
    test_corner();
    test_overlapping_triangle();
    test_linear_triangle();
}