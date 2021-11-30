#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <unordered_map>
#include <functional>
#include "../Todolist/constants.h"

std::function<bool(char)> string_predicates(const std::string& protocol)
{
    std::unordered_map<std::string, std::function<bool(char)>> predicates;

    predicates.insert(std::make_pair("Default", 
    [](char test){return isalpha(test);}));
    predicates.insert(std::make_pair("AlphaSpace",
    [](char test){return isalpha(test) || isspace(test);}));

    auto x = predicates.find(protocol);
    if(x == predicates.end()) return predicates.find("Default")->second;
    return x->second;
}

std::string get_string(const std::string& request, std::function<bool(char)> predicate)
{
    std::string user_input;
    bool verified = false;

    while(!verified)
    {
        std::cout << request;
        std::getline(std::cin, user_input);

        if(std::all_of(user_input.begin(), user_input.end(), predicate))verified = true;
    }

    return user_input;
}

int get_a_time_from_user(const std::string& request, int min_range, int max_range)
{
    std::string string_input;
    bool verified = false;

    while(!verified)
    {
        std::cout << "enter the " << request << " here("  <<  min_range << '-' << max_range << "): ";
        std::getline(std::cin, string_input);

        if(std::all_of(string_input.begin(), string_input.end(),
        [](char to_test){return isdigit(to_test);}))
        {
            if(std::stoi(string_input) >= min_range && std::stoi(string_input) <= max_range)verified = true;
        }  
    }
    return std::stoi(string_input);
} 

void get_a_date_from_user(std::tm& to_return)
{
    to_return.tm_mon= get_a_time_from_user("month", constants::current_date->tm_mon, 11);
    to_return.tm_mday = get_a_time_from_user("day", constants::current_date->tm_mday, constants::months_ceiling[constants::current_date->tm_mon]);
}

void replace_char_with(std::string& to_modify, char to_replace, 
char replacement)
{
    std::replace_if(to_modify.begin(), to_modify.end(),
    [to_replace](auto test)
    {return to_replace == test;},replacement);
}
