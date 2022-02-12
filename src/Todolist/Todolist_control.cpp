#include "Todolist_control.h"

Todolist_control::Todolist_control(const std::shared_ptr<Todolist_model>& model)
    : model_ptr{model}
{
}

void Todolist_control::add_to_list(const std::initializer_list<std::string>& fields) const
{
    auto extracted_strings_ptr{std::data(fields)};

    model_ptr->add_to_list(*(extracted_strings_ptr + 0));
}

void Todolist_control::remove_from_list(const std::initializer_list<std::string>& fields) const
{
    auto extracted_strings_ptr{std::data(fields)};

    model_ptr->remove_from_list(*(extracted_strings_ptr + 0));
}