#pragma once

#include <ostream>
#include <string>

class Person 
{
    Person(const unsigned int& id_, const std::string& name_) : id(id_), name(name_)
    {}

    unsigned int id;
    std::string name;

    class PersonFactory 
    {
        PersonFactory() {}

        static unsigned int id;

    public:
        static Person create_person(const std::string& name) 
        {
            return Person{id++, name};
        }
    };

public:
    ~Person() = default;

    static PersonFactory Factory;

    friend std::ostream& operator<<(std::ostream& os, const Person& obj)
    { return os << "Person: id = " << obj.id << " name = " << obj.name; }
};
