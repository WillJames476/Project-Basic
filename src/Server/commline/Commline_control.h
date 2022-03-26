#ifndef COMMLINE_CONTROL_H
#define COMMLINE_CONTROL_H

#include <memory>
#include <interfaces/Control_interface.hpp>
#include "Commline_model.h"


class Commline_control : public Control_interface<Commline_control>
{
public:

  Commline_control(const std::shared_ptr<Commline_model>& model);

  bool
  add_to_list(const std::initializer_list<std::string>& fields) const;

  bool
  add_to_list_access(const std::initializer_list<std::string>& fields) const;

  bool
  remove_from_list(const std::initializer_list<std::string>& fields) const;

  bool
  remove_from_list_access(const std::initializer_list<std::string>& fields) const;

  std::string
  modify_permission(const std::initializer_list<std::string>& fields) const;

  bool
  is_user_permitted(const std::initializer_list<std::string>& fields) const;

private:

  std::shared_ptr<Commline_model> model_ptr;

};

#endif
