#pragma once

#include <ostream>

struct Point
{
    int x{0}, y{0};

    Point() {}

    Point(const int x, const int y) : x{x}, y{y} {}

    Point(const Point &rhs) : x{rhs.x}, y{rhs.y} {}

    friend std::ostream &operator<<(std::ostream &o, const Point &p)
    {
        o << "x: " << p.x << " y: " << p.y;
        return o;
    }
};