#pragma once

#include <ostream>
#include <string>
#include <vector>

struct Field 
{
    std::string name, type;

    Field(const std::string& name_, const std::string& type_) : name(name_), type(type_) {}

    friend std::ostream& operator<<(std::ostream& os, const Field& obj)
    {
        os << obj.type << " " << obj.name << ";";
        return os;
    }
};

class CodeBuilder
{
    std::string class_name;
    std::vector<Field> fields;

    static constexpr unsigned int indent_spaces = 2;

public:
    explicit CodeBuilder(const std::string& class_name) : class_name(class_name)
    {}

    CodeBuilder& add_field(const std::string& name, const std::string& type)
    {
        if(!name.empty() && !type.empty())
            fields.emplace_back(name, type);

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const CodeBuilder& obj)
    {
        os << "class " << obj.class_name << "\n{\n";

        for(auto& f : obj.fields)
        {
            for(auto i = 0; i < obj.indent_spaces; i++)
                os << " ";
            os << f << "\n";
        }
        
        os << "};" << std::endl;

        return os;
    }
};
