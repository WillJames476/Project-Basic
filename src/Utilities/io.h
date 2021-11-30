#ifndef IO_H
#define IO_H

#include <string>
#include <ctime>
#include <sstream>
#include <algorithm>

template <typename T>
std::string vector_to_string(const std::vector<T>& to_process,char delimiter)
{
    std::ostringstream data;

    for(auto x : to_process)data << x << delimiter;

    return data.str();
}

template <typename T>
std::vector<T> string_to_list(std::string& to_process, char delimiter)
{
    std::replace_if(to_process.begin(), to_process.end(),
    [delimiter](auto test){return test == delimiter;},' ');
    std::istringstream data(to_process);

    std::initializer_list<T>to_give;
    return to_give;
}


std::string extract_alpha_space_string_from_user(const std::string &request);
std::string extract_allpha_string_from_user(const std::string &request);
void get_a_date_from_user(std::tm& to_return);
int get_a_time_from_user(const std::string& request, 
int min_range, int max_range);
void replace_char_with(std::string& to_modify, char to_replace, 
char replacement);

#endif