#include <string>
#include <vector>

#include "control_agregate.h"

std::string delete_account(const Control_agregate& controls,
			   const std::vector<std::string>& fields)
{
  std::string string_to_return{"failure\n"};

  bool is_user_loged_in {controls.account.is_login_verified({fields[0], fields[1]})};

  if(is_user_loged_in)
    {
      controls.account.remove_from_list({fields[0], fields[1]});
      controls.commline.remove_from_list({fields[0]});
      controls.todolist.remove_from_list({fields[0]});
      string_to_return = "done\n";
    }

  return string_to_return;
}

std::string delete_a_line(const Control_agregate& controls,
			  const std::vector<std::string>& fields)
{
  std::string string_to_return {"failure\n"};

  bool is_user_loged_in {controls.account.is_login_verified({fields[0], fields[1]})};

  if(is_user_loged_in)
    {
      controls.commline.remove_from_list_access({fields[0], fields[2]});
      string_to_return = "done\n";
    }

  return string_to_return;
}

std::string delete_a_task(const Control_agregate& control,
			  const std::vector<std::string>& fields)
{
  std::string string_to_return{"failure\n"};

  bool is_user_loged_in{control.account.is_login_verified({fields[0], fields[1]})},
       is_permitted    {control.commline.is_user_permitted({fields[0], fields[2]})};

  if(is_user_loged_in && is_permitted)
    {
      control.todolist.remove_from_list_task({fields[0], fields[3], fields[2]});
      string_to_return = "done\n";
    }
    
  return string_to_return;
}
