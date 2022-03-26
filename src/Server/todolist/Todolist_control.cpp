#include "Todolist_control.h"

Todolist_control::Todolist_control(const std::shared_ptr<Todolist_model>& model)
  : model_ptr{model}
{
}

bool
Todolist_control::add_to_list(const std::initializer_list<std::string>& fields) const
{
  const auto& extracted_strings_ptr{std::begin(fields)};

  return model_ptr->add_to_list(extracted_strings_ptr[0]);
}

bool
Todolist_control::add_to_list_task(const std::initializer_list<std::string>& fields) const
{
  const auto& extracted_strings_ptr{std::begin(fields)};

  return model_ptr->add_to_list_task(extracted_strings_ptr[0],
				     extracted_strings_ptr[1],
				     extracted_strings_ptr[2]);
}

bool
Todolist_control::remove_from_list(const std::initializer_list<std::string>& fields) const
{
  const auto& extracted_strings_ptr{std::begin(fields)};

  return model_ptr->remove_from_list(extracted_strings_ptr[0]);
}

bool
Todolist_control::remove_from_list_task(const std::initializer_list<std::string>& fields) const
{
  const auto& extracted_strings_ptr{std::begin(fields)};

  return model_ptr->remove_from_list_task(extracted_strings_ptr[0],
					  extracted_strings_ptr[1],
					  extracted_strings_ptr[2]);
}
