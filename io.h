#ifndef IO_H
#define IO_H

#include <string>
#include <ctime>

std::string extract_alpha_space_string_from_user(const std::string &request);
std::string extract_allpha_string_from_user(const std::string &request);
void get_a_date_from_user(std::tm& to_return);
int get_a_time_from_user(const std::string& request, int min_range, int max_range);

#endif