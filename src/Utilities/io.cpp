#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <regex>

#include "../Todolist/constants.h"
#include "io.h"

std::string get_string(const std::string& request, std::regex predicate)
{
    std::string user_input{};
    bool is_verified{false};

    while(!is_verified)
    {
        std::cout << request;
        std::getline(std::cin, user_input);

        is_verified = std::regex_match(user_input, predicate);
    }

    return user_input;
}

void get_a_date_from_user(std::tm& to_return)
{
    to_return.tm_mon= get_integral<int>
    ("enter the month here: ", constants::current_date->tm_mon - 1, 12);
    to_return.tm_mday = get_integral<int>
    ("enter the day here: ", constants::current_date->tm_mday - 1, 
    constants::months_ceiling[constants::current_date->tm_mon] + 1);
}

void replace_char_with(std::string& to_modify, char to_replace, 
char replacement)
{
    std::replace_if(to_modify.begin(), to_modify.end(),
    [to_replace](auto& test)
    {return to_replace == test;},replacement);
}
