#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
#include <sstream>
#include <boost/format.hpp>

#include "io.h"

std::string get_string(const std::string& request
                    , std::regex predicate)
{
    std::string output {};
    bool is_verified   {false};

    while(!is_verified)
    {
        std::cout << request;
        std::getline(std::cin, output);
        is_verified = std::regex_match(output, predicate);
    }

    return output;
}

void replace_char_with(std::string& to_modify
                    , char to_replace
                    , char replacement)
{
    std::replace_if(to_modify.begin(), to_modify.end(),
    [to_replace](auto& test)
    {return to_replace == test;},replacement);
}

bool arguments_verify(const std::vector<std::string>& arguments
                    , const std::initializer_list<std::regex>& predicates)
{
    int tracker {0};

    for(const auto& x : predicates)
    {
        if(!std::regex_match(arguments[tracker], x))
        {
            return false;
        }

        ++tracker;
    }

    return true;
}

void invalid_argument_quantity_error(const std::string& command
                                    , int expected_size)
{
    using namespace FEEDBACK_COLORS;
    std::stringstream output;

    output << boost::format("%s%s expects: %d arguments%s\n") 
        % BAD
        % command 
        % expected_size 
        % RESET;

    std::cerr << output.str();
}

void invalid_argument_error(const std::string& command)
{
    using namespace FEEDBACK_COLORS;
    std::stringstream output;

    output << boost::format("%s%s arguments are invalid%s\n")
        % BAD 
        % command
        % RESET;

    std::cerr << output.str();
}
