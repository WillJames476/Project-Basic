#include <string>
#include <vector>
#include <io.h>
#include <agregates/control_agregate.h>

std::string
delete_account(const Control_agregate& controls,
	       const std::vector<std::string>& fields)
{
  std::string string_to_return{FEEDBACK_COLORS::OPERATION_FAILURE};

  bool is_user_loged_in {controls.account.is_login_verified({fields[0], fields[1]})};

  if(is_user_loged_in)
    {
      bool is_deletion_succes{
	controls.account.remove_from_list({fields[0], fields[1]})
	&& controls.commline.remove_from_list({fields[0]})
	&& controls.todolist.remove_from_list({fields[0]})};

      if(is_deletion_succes)
	{
	  string_to_return = FEEDBACK_COLORS::OPERATION_SUCESS;
	}
    }

  return string_to_return;
}

std::string
delete_a_line(const Control_agregate& controls,
	      const std::vector<std::string>& fields)
{
  std::string string_to_return {FEEDBACK_COLORS::OPERATION_FAILURE};
  bool is_user_loged_in {controls.account.is_login_verified({fields[0], fields[1]})};

  if(is_user_loged_in)
    {
      bool is_line_deleted {controls.commline.remove_from_list_access({fields[0], fields[2]})};

      if(is_line_deleted)
	{
	  string_to_return = FEEDBACK_COLORS::OPERATION_SUCESS;
	}
    }

  return string_to_return;
}

std::string
delete_a_task(const Control_agregate& control,
	      const std::vector<std::string>& fields)
{
  std::string string_to_return{FEEDBACK_COLORS::OPERATION_FAILURE};

  bool is_user_loged_in {control.account.is_login_verified({fields[0], fields[1]})};

  if(is_user_loged_in)
    {
      bool is_task_deleted {control.todolist.remove_from_list_task({fields[0], fields[3], fields[2]})};

      if(is_task_deleted)
	{
	  string_to_return = FEEDBACK_COLORS::OPERATION_SUCESS;
	}
    }
    
  return string_to_return;
}
