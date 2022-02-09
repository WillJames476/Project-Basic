#include "Commline_control.h"

#include <iostream>

Commline_control::Commline_control(const std::shared_ptr<Commline_model>& model)
    : model_ptr{model}
{
}

void Commline_control::add_to_list(const std::initializer_list<std::string>& fields) const
{
    auto strings_ptr{std::data(fields)};

    model_ptr->add_to_list(*(strings_ptr + 0));
}

std::string Commline_control::add_to_list_access(const std::initializer_list<std::string>& fields) const
{
    auto strings_ptr{std::data(fields)};
 
    model_ptr->add_to_list_acess(*(strings_ptr + 0)
                                , *(strings_ptr + 1)
                                , std::stoi(*(strings_ptr + 2)));

    return std::string{"done"};
}

void Commline_control::remove_from_list(const std::initializer_list<std::string>& fields) const
{
    auto strings_ptr{std::data(fields)};

    model_ptr->remove_from_list(*(strings_ptr + 0));
}

std::string Commline_control::remove_from_list_access(const std::initializer_list<std::string>& fields) const
{
    auto strings_ptr{std::data(fields)};

    model_ptr->remove_from_list_acess(*(strings_ptr + 0)
                                , *(strings_ptr + 1));

    return std::string{"done"};
}