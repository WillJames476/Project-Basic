#ifndef SERVER_CONTROL_UTILITIES_H
#define SERVER_CONTROL_UTILITIES_H

#include <sstream>
#include <vector>

#include "io.h"
#include "control_agregate.h"
#include "file_agregates.h"
#include "view_agregate.h"

std::string get_control(std::istringstream& message
                , const View_agregate& controls);

std::string post_control(std::istringstream& message
                    , const Control_agregate& controls);

std::string delete_control(std::istringstream& message
                    , const Control_agregate& controls);

std::string put_control(std::istringstream& message
                    , const Control_agregate& view);

void file_control(const std::string& mode
                , File_agregate& file);

template <typename T, typename X, typename V, typename Z>
std::string apply_function(const X& application
                        , const std::vector<std::string>& list
                        , const V& regex_predicates
                        , size_t expected_size
                        , const Z& controls
                        , const T& function)
{
    std::string feedback{};

    if(expected_size == list.size())
    {
        if(arguments_verify(list, regex_predicates))
        {
            feedback = function(controls, list);
        }
        else
        {
            feedback = invalid_argument_error(application);
        }
    }
    else
    {
        feedback = invalid_argument_quantity_error(application, expected_size);
    }

    return feedback;
}

#endif
