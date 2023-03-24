# Prototype

A partially or fully initialized object that you copy (clone) and make use of.

1. Prototype - Can be implemented by means of copy constructor or copy assignment.
1. Prototype Factory - Generate a prototype using the the [Factory](../factory/) pattern.
1. Prototype via serialization - Use a serialization interface (such as boost::serialization) to both have serialization and prototyping.

For the solution expected by the automated evaluator, the following code suffices:

```cpp
struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}
  
  Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line
{
  Point *start, *end;
  
  Line(Point* const start, Point* const end)
    : start(start), end(end)
  {
  }

  ~Line()
  {
    delete start;
    delete end;
  }

  Line deep_copy() const
  { return Line( new Point(start->x, start->y), new Point(end->x, end->y) ); }
};
```
