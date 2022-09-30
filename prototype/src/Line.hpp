#pragma once

#include "Point.hpp"

#include <memory>
#include <ostream>

struct Line
{
    //Even though I'd probably not use pointers here, I decided to use unique_ptr to
    //keep with the deep copy intent of the exercise.
    std::unique_ptr<Point> start, end;

    Line(Point *const start, Point *const end)
        : start(start), end(end)
    {
    }

    ~Line() = default;

    Line(const Line &rhs)
        : start(new Point(*rhs.start)), end(new Point(*rhs.end))
    {
    }

    friend std::ostream& operator<< (std::ostream& o, const Line& l)
    {
        o << "start: " << *l.start << " end: " << *l.end;
        return o;
    }
};
