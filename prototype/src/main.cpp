#include "Line.hpp"
#include "Point.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    Line a{new Point{0,0}, new Point{2,2}};
    Line b = a;

    b.start->x = -1;
    b.start->y = -2;

    std::cout << a << std::endl << b << std::endl;
    return 0;
}
