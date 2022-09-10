# Factory

There are four Factories (only 2 in the GOF book):

1. Factory method
2. Factory
3. Inner Factory
4. Abstract Factory

The implementation provided here differs from the one needed to be submitted for the course. It is more complex, hiding details from the outside world using a inner factory approach, and uses a static id for the PersonFactory.

For the solution expected by the automated evaluator, the following code suffices:

```cpp
#include <string>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory 
{
    public:
    PersonFactory() : id(0) {}

    int id;

    Person create_person(const std::string& name) 
    {
        return Person{id++, name};
    }
};
```