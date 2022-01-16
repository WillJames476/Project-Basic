#include <vector>
#include <string>
#include <regex>
#include <functional>

#include "io.h"

template<typename T>
void apply_function(T& list
    ,const std::vector<std::string>& fields
    ,const int required_size
    ,const std::string function_name
    ,const std::initializer_list<std::regex>& predicates
    ,void (*function)(T&, const std::vector<std::string>&))
{
    if(static_cast<int>(fields.size()) == required_size)
    {
        if(arguments_verify(fields, predicates))
        {
            function(list, fields);
        }
        else
        {
            invalid_argument_error(function_name);
        }
    }
    else
    {
        invalid_argument_quantity_error(function_name, required_size);
    }
}

template <typename T>
void apply_function(const std::vector<std::string>& fields
    ,const int required_size
    ,const std::string function_name
    ,const std::initializer_list<std::regex>& predicates
    ,const std::function<void(const std::vector<std::string>&)>& function)
{
    if(static_cast<int>(fields.size()) == required_size)
    {
        if(arguments_verify(fields, predicates))
        {
            function(fields);
        }
        else
        {
            invalid_argument_error(function_name);
        }
    }
    else
    {
        invalid_argument_quantity_error(function_name, required_size);
    }
}

template <typename T, typename X>
X apply_function(const std::vector<std::string>& fields
    ,const int required_size
    ,const std::string function_name
    ,const std::initializer_list<std::regex>& predicates
    ,const std::function<X(const std::vector<std::string>&)>& function)
{
    if(static_cast<int>(fields.size()) == required_size)
    {
        if(arguments_verify(fields, predicates))
        {
            return function(fields);
        }
        else
        {
            invalid_argument_error(function_name);
        }
    }
    else
    {
        invalid_argument_quantity_error(function_name, required_size);
    }

    return X{};
}