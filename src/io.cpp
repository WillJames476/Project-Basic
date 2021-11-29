#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include "Todolist/constants.h"

std::string extract_alpha_space_string_from_user(const std::string &request)
{
    std::string output;
    bool verified = false;

    while(!verified)
    {
        std::cout << "entert the " << request << " here: ";
        std::getline(std::cin, output);

        if(std::all_of(output.begin(), output.end(),
        [](char to_test){return isalpha(to_test) || isspace(to_test);})) verified = true;
    }

    return output;
}

std::string extract_allpha_string_from_user(const std::string &request)
{
    std::string output;
    bool verified = false;

    while(!verified)
    {
        std::cout << "enter the " << request << " here: ";
        std::getline(std::cin, output);

        if(std::all_of(output.begin(), output.end(),
        [](char to_test){return isalpha(to_test);})) verified = true;
    }

    return output;
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