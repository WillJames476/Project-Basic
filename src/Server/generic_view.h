#ifndef GENERIC_VIEW_H
#define GENERIC_VIEW_H

#include <string>
#include <type_traits>

template <typename T, typename func>
std::string view_raw(const T& to_view, const func& to_call)
{
    static_assert(not std::is_function<func>::value);

    std::string to_return_string{};

    return to_call(to_view);
}

#endif