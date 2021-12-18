#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <unordered_map>
#include <functional>
#include <cstring>

#include "../Todolist/constants.h"
#include "io.h"

std::function<bool(char)> string_predicates(const std::string& protocol)
{
    std::unordered_map<std::string, std::function<bool(char)>> predicates;

    predicates.insert(std::make_pair("Default", [](char test){return isalpha(test);}));
    predicates.insert(std::make_pair("AlphaSpace",[](char test){return isalpha(test) || isspace(test);}));
    predicates.insert(std::make_pair("Message",[](char test){return isprint(test) || isspace(test) || iscntrl(test);}));
    predicates.insert(std::make_pair("Contact",[](char test){return isdigit(test);}));
	predicates.insert(std::make_pair("Email",[](char test){return isprint(test);}));

    auto x = predicates.find(protocol);
    if(x == predicates.end()) return predicates.find("Default")->second;
    return x->second;
}

std::string get_string(const std::string& request, std::function<bool(char)> predicate)
{
    std::string user_input;
    bool verified{false};

    while(!verified)
    {
        std::cout << request;
        std::getline(std::cin, user_input);

        if(std::all_of(user_input.begin(), user_input.end(), predicate))verified = true;
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
