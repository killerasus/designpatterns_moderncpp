#include <algorithm>
#include <array>
#include <iostream>

struct Square
{
    int side{0};

    explicit Square(const int side)
        : side(side)
    {
    }
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle
{
    explicit SquareToRectangleAdapter(const Square &square)
    : m_square(square)
    {}

    int width() const override { return m_square.side; }

    int height() const override { return m_square.side; }
    
    const Square& m_square;
};

int main(void)
{
    using S2RA = SquareToRectangleAdapter;
    std::array<Square, 3> squares{Square{5}, Square{6}, Square{10}};
    auto printRectArea = [](const Rectangle& r) { std::cout << "Area = " << r.area() << std::endl; };
    
    std::for_each(squares.begin(), squares.end(), [&](auto& s){ printRectArea(S2RA{s}); });

    return 0;
}