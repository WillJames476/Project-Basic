#ifndef IO_H
#define IO_H

#include <string>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
#include <regex>
#include <fstream>

namespace FEEDBACK_COLORS
{
    const std::string BASE  {"\u001b["},
                      GOOD  {BASE + "32m"},
                      BAD   {BASE + "31m"},
                      RESET {BASE + "0m"};
}

namespace REGEX_PREDICATES
{
    const std::regex ALPHA         ("[A-Za-z ]+"),
                     ALPHA_NOSPACE ("[A-Za-z]+"),
                     MESSAGE       ("[A-Za-z0-9, \n]+"),
                     DIGIT         ("[0-9 ]+"),
                     DIGIT_NOSPACE ("[0-9]+"),
                     ALNUM         ("[A-Za-z0-9 ]+"),
                     EMAIL         ("[_@a-zA-Z0-9]+.com"),
                     APP_COMMAND   ("^--[a-z ]+"),
                     COMMAND       ("^/[a-z-0-9"" -]+");
}

template <typename T>
T get_integral(const std::string& request, T min, T max)
{
    static_assert(std::is_integral<T>::value, "type must be integral\n");

    T to_return;
    bool verified{false};

    while(!verified)
    {
        std::cout << request;
        std::string input_extractor;
        std::getline(std::cin, input_extractor);
        std::istringstream(input_extractor) >> to_return;

        if(to_return > min && to_return < max) verified = true;
    }

    return to_return;
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
        std::cerr << BAD << excpt.what() << RESET;
        return EXIT_FAILURE;
    }

    std::clog << GOOD << "file operation suceeds success\n" << RESET;
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
        std::cerr << BAD << excpt.what() << RESET;
        return EXIT_FAILURE;
    }

    std::clog << GOOD << "file operation suceeds success\n" << RESET;
    return EXIT_SUCCESS;
}
void invalid_argument_quantity_error(const std::string& command, int expected_size);
std::string get_string(const std::string& request, std::regex predicate);
void get_a_date_from_user(std::tm& to_return);
int get_a_time_from_user(const std::string& request,
int min_range, int max_range);
void replace_char_with(std::string& to_modify, char to_replace,
char replacement);

#endif
