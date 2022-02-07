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
    const std::string BASE  {"\u001b["},
                      GOOD  {BASE + "32m[SUCCESSFULL] "},
                      BAD   {BASE + "31m[ERROR] "},
                      RESET {BASE + "0m"};
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

template <typename T>
int save_to_file(const std::string& file_name, const T& to_modify)
{
    using namespace FEEDBACK_COLORS;

    try
    {
        std::ofstream file_archiver(file_name);
        file_archiver << to_modify;
        file_archiver.close();
    }
    catch(std::exception &excpt)
    {
        std::cerr << BAD << excpt.what() << RESET << '\n';
        return EXIT_FAILURE;
    }

    std::clog << GOOD << "file operation suceeds success\n" << RESET << '\n';
    return EXIT_SUCCESS;
}

template <typename T>
int load_from_file(const std::string& file_name, T& to_modify)
{
    using namespace FEEDBACK_COLORS;

    try
    {
        std::ifstream file_archiver(file_name);
        file_archiver >> to_modify;
        file_archiver.close();
    }
    catch(std::exception &excpt)
    {
        std::cerr << BAD << excpt.what() << RESET << '\n';
        return EXIT_FAILURE;
    }

    std::clog << GOOD << "file operation suceeds success\n" << RESET << '\n';
    return EXIT_SUCCESS;
}

std::string get_string(const std::string& request, std::regex pattern);
void invalid_argument_error(const std::string& command);
bool arguments_verify(const std::vector<std::string>& arguments, const std::initializer_list<std::regex>& predicates);
void invalid_argument_quantity_error(const std::string& command, int expected_size);
void replace_char_with(std::string& to_modify, char to_replace,
char replacement);

#endif
