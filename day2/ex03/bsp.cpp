#include "Point.hpp"

static long long crossProduct(Point const p1, Point const p2, Point const p3) {
    long long x1 = p1.getX().getRawBits();
    long long y1 = p1.getY().getRawBits();
    long long x2 = p2.getX().getRawBits();
    long long y2 = p2.getY().getRawBits();
    long long x3 = p3.getX().getRawBits();
    long long y3 = p3.getY().getRawBits();
    return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

bool bsp(Point const a, Point const b, Point const c, Point const o) {
    long long d1 = crossProduct(a, b, o);
    long long d2 = crossProduct(b, c, o);
    long long d3 = crossProduct(c, a, o);
    return (d1 < 0 && d2 < 0 && d3 < 0) || (d1 > 0 && d2 > 0 && d3 > 0);
}