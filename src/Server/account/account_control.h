#ifndef ACCOUNT_CONTROL_H
#define ACCOUNT_CONTROL_H

#include <memory>
#include <string>
#include <array>
#include <interfaces/Control_interface.hpp>
#include "account_model.h"


class Account_control : public Control_interface<Account_control>
{
public:

  Account_control(const std::shared_ptr<Account_model>& model);

  bool
  add_to_list(const std::initializer_list<std::string>& fields) const;

  bool
  remove_from_list(const std::initializer_list<std::string>& fields) const;

  std::string
  get_from_list(const std::initializer_list<std::string>& fields) const;

  bool
  is_user_existing(const std::string& username) const;

  bool
  is_login_verified(const std::array<std::string, 2>& fields) const;

private:

  std::shared_ptr<Account_model>model;
  
};

#endif
