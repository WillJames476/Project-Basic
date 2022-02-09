#include "Commline_control.h"

Commline_control::Commline_control(const std::shared_ptr<Commline_model>& model)
    : model_ptr{model}
{
}

void Commline_control::add_to_list(const std::initializer_list<std::string>& fields) const
{
    auto strings_ptr{std::data(fields)};

    model_ptr->add_to_list(*(strings_ptr + 0));
}

void Commline_control::remove_from_list(const std::initializer_list<std::string>& fields) const
{
    auto strings_ptr{std::data(fields)};

    model_ptr->remove_from_list(*(strings_ptr + 0));
}