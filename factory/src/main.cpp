#include "Person.hpp"

#include <iostream>

int main(void)
{
    auto p = Person::Factory.create_person("John");
    auto o = Person::Factory.create_person("Joseph");

    std::cout << p << std::endl;
    std::cout << o << std::endl;

    return 0;
}
