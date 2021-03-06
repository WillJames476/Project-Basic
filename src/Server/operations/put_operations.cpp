#include <string>
#include <vector>
#include <io.h>
#include <agregates/control_agregate.h>

std::string
change_commline_permission(const Control_agregate& control,
			   const std::vector<std::string>& fields)
{
  std::string string_to_return{FEEDBACK_COLORS::OPERATION_FAILURE};

  bool is_login_verified {control.account.is_login_verified({fields[0], fields[1]})};
  bool is_user_existing  {control.account.is_user_existing(fields[2])};

  if(is_login_verified && is_user_existing)
    {
      control.commline.modify_permission({fields[0], fields[2], fields[3]});
      string_to_return = FEEDBACK_COLORS::OPERATION_SUCESS;
    }
  
  return string_to_return;
}
