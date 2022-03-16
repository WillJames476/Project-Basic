#include <string>
#include <vector>

#include "control_agregate.h"
#include "view_agregate.h"

std::string get_account_info(const View_agregate& view,
			     const Control_agregate& control,
			     const std::vector<std::string>& fields)
{
  std::string string_to_return{"failure\n"};

  bool is_login_verified{control.account.is_login_verified({fields[0], fields[1]})};

  if(is_login_verified)
    {
      string_to_return = view.account.send_formatted(fields[0]);
    }

  return string_to_return;
}

std::string get_commline_table(const View_agregate& view,
			     const Control_agregate& control,
			     const std::vector<std::string>& fields)
{
  std::string string_to_return{"failure\n"};

  bool is_login_verified{control.account.is_login_verified({fields[0], fields[1]})};

  if(is_login_verified)
    {
      string_to_return = view.commline.send_formatted(fields[0]);
    }
  
  return string_to_return;
}
