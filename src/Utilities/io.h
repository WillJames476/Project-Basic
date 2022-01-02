#ifndef IO_H
#define IO_H

#include <string>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

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

std::string get_string(const std::string& request, std::function<bool(char)> predicate);
std::function<bool(char)>string_predicates(const std::string& protocol);
void get_a_date_from_user(std::tm& to_return);
int get_a_time_from_user(const std::string& request, 
int min_range, int max_range);
void replace_char_with(std::string& to_modify, char to_replace, 
char replacement);

#endif
