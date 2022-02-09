#ifndef IO_H
#define IO_H

#include <string>
#include <sstream>
#include <iostream>
#include <type_traits>
#include <vector>
#include <regex>
#include <fstream>

#include <boost/format.hpp>

namespace FEEDBACK_COLORS
{
    const std::string BASE              {"\u001b["},
                      GOOD              {BASE + "32m[SUCCESSFULL] "},
                      BAD               {BASE + "31m[ERROR] "},
                      RESET             {BASE + "0m"},
                      OPERATION_FAILURE {BAD + "operation failure" + RESET},
                      OPERATION_SUCESS  {GOOD + "operation suceeds" + RESET};
}

namespace REGEX_PREDICATES
{
    const std::regex ALPHA         ("[A-Za-z ]+"),
                     ALPHA_NOSPACE ("[A-Za-z]+"),
                     MESSAGE       ("[A-Za-z0-9, \n]+"),
                     DIGIT         ("[0-9 ]+"),
                     DIGIT_NOSPACE ("[0-9]+"),
                     DATE          ("^3[0-1]|[12][0-9]|[0-9]$"),
                     MONTH         ("^1[0-2]+|[0-9]{1}+$"),
                     ALNUM         ("[A-Za-z0-9 ]+"),
                     EMAIL         ("[_@a-zA-Z0-9]+.com"),
                     APP_COMMAND   ("^--[a-z ]+"),
                     BOOLEAN       ("^[0-1]$"),
                     COMMAND       ("^/[a-z-0-9"" -]+");
}

std::string get_string(const std::string& request
                    , std::regex pattern);

std::string invalid_argument_error(const std::string& command);

bool arguments_verify(const std::vector<std::string>& arguments
                    , const std::initializer_list<std::regex>& predicates);

std::string invalid_argument_quantity_error(const std::string& command
                                    , int expected_size);

void replace_char_with(std::string& to_modify
                    , char to_replace
                    , char replacement);

#endif
