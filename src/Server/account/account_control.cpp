#include "account_control.h"
#include <algorithm>
#include <array>
#include <string>

Account_control::Account_control(const std::shared_ptr<Account_model>& account_model)
  : model{account_model}
{
}

bool
Account_control::add_to_list(const std::initializer_list<std::string>& fields) const
{
  if(fields.size() == 2)
    {
      const auto& datas{std::begin(fields)};

      if(model->add_to_list(datas[0], datas[1]))
	{
	  return true;
        }
    }

  return false;
}

bool
Account_control::remove_from_list(const std::initializer_list<std::string>& fields) const
{
  if(fields.size() == 2)
    {
      const auto& datas{std::begin(fields)};

      if(model->remove_from_list(datas[0], datas[1]))
	{
	  return true;
        }
    }

  return false;
}

std::string
Account_control::get_from_list(const std::initializer_list<std::string>& fields) const
{
  std::string string_to_return{"unsuccessfull operation"};

  if(fields.size() == 2)
    {
      const auto& datas{std::begin(fields)};

      if(model->get_item_from_list(datas[0], datas[1]))
	{
	  string_to_return = datas[0] + " " + datas[1];
        }
    }

  return string_to_return;
}

bool
Account_control::is_user_existing(const std::string& username) const
{
  return model->get_is_account_existing(username);
}

bool
Account_control::is_login_verified(const std::array<std::string, 2>& fields) const
{
  return model->get_item_from_list(fields[0], fields[1]);
}
