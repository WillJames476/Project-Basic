#ifndef GENERIC_VIEW_FILE_H
#define GENERIC_VIEW_FILE_H

#include <string>
#include <type_traits>
#include "account_model.h" 


template <typename T, typename func>
std::string view_raw(const T& to_view, const func& to_call)
{
    static_assert(not std::is_function<func>::value);

    std::string to_return_string{};

    return to_call(to_view);
}

template <typename T, typename func>
void save_file(const T& to_save, const func& to_call)
{
    static_assert(not std::is_function<func>::value);
    std::string to_save_string{view_raw(to_save, to_call)};
}

template <typename T, typename func>
void read_file(const T& to_read, const func& to_call)
{
    static_assert(not std::is_function<func>::value);
}

#endif