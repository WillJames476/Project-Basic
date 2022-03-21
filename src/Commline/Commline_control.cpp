#include "Commline_control.h"

Commline_control::Commline_control(const std::shared_ptr<Commline_model>& model)
    : model_ptr{model}
{
}

bool Commline_control::add_to_list(const std::initializer_list<std::string>& fields) const
{
  auto strings_ptr{std::data(fields)};

  return model_ptr->add_to_list(*(strings_ptr + 0));
}

std::string Commline_control::add_to_list_access(const std::initializer_list<std::string>& fields) const
{
    auto strings_ptr{std::data(fields)};
 
    model_ptr->add_to_list_acess(*(strings_ptr + 0)
                                , *(strings_ptr + 1)
                                , std::stoi(*(strings_ptr + 2)));

    return std::string{"done"};
}

bool Commline_control::remove_from_list(const std::initializer_list<std::string>& fields) const
{
  auto strings_ptr{std::data(fields)};

  return model_ptr->remove_from_list(*(strings_ptr + 0));
}

std::string Commline_control::remove_from_list_access(const std::initializer_list<std::string>& fields) const
{
    auto strings_ptr{std::data(fields)};

    model_ptr->remove_from_list_acess(*(strings_ptr + 0)
                                , *(strings_ptr + 1));

    return std::string{"done"};
}

std::string Commline_control::modify_permission(const std::initializer_list<std::string>& fields) const
{
    auto strings_ptr{std::data(fields)};

    model_ptr->modify_permission(*(strings_ptr + 1)
                            , *(strings_ptr + 0)
                            , std::stoi(*(strings_ptr + 2)));

    return std::string{};
}

bool Commline_control::is_user_permitted(const std::initializer_list<std::string>& fields) const
{
  auto strings_ptr{std::data(fields)};

  return model_ptr->is_permitted(*(strings_ptr + 0),
				 *(strings_ptr + 1));
}
