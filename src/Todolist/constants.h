#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <array>
#include <ctime>

namespace constants
{
    const std::time_t current_time = std::time(0);
    const std::tm * const current_date = std::localtime(&current_time);
    const std::array<int,12>months_ceiling{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
}

#endif