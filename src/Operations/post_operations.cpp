#include <string>
#include <vector>
#include <input_output/io.h>
#include <server/control_agregate.h>

std::string add_new_account(const Control_agregate& control,
			    const std::vector<std::string>& fields)
{ 
  std::string string_to_return {FEEDBACK_COLORS::OPERATION_FAILURE};
  bool is_creation_verified    {control.account.add_to_list({fields[0], fields[1]})};

  if(is_creation_verified)
    {
      bool is_entries_created{control.commline.add_to_list({fields[0]})
	&& control.todolist.add_to_list({fields[0]})};

      if(is_entries_created)
	{
	  string_to_return = FEEDBACK_COLORS::OPERATION_SUCESS;
	}
    }

  return string_to_return;
}

std::string add_new_commline(const Control_agregate& control,
			     const std::vector<std::string>& fields)
{
  std::string string_to_return {FEEDBACK_COLORS::OPERATION_FAILURE};
  bool is_login_verified       {control.account.is_login_verified({fields[0], fields[1]})};
  bool is_target_existing      {control.account.is_user_existing(fields[2])};

  if(is_login_verified && is_target_existing)
    {
      bool is_line_added {control.commline.add_to_list_access({fields[0], fields[2], "0"})};
      if(is_line_added)
	{
	  string_to_return = FEEDBACK_COLORS::OPERATION_SUCESS;
	}
    }

  return string_to_return;
}

std::string add_new_task(const Control_agregate& control,
			 const std::vector<std::string>& fields)
{
  std::string string_to_return{FEEDBACK_COLORS::OPERATION_FAILURE};

  bool is_login_verified {control.account.is_login_verified({fields[0], fields[1]})};
  bool is_target_existent {control.account.is_user_existing(fields[2])};

  if(is_login_verified && is_target_existent)
    {
      bool is_user_permitted{control.commline.is_user_permitted({fields[0], fields[2]})};
      if(is_user_permitted)
	{
	  bool is_task_added {control.todolist.add_to_list_task({fields[2], fields[0], fields[3]})};

	  if(is_task_added)
	    {
	      string_to_return = FEEDBACK_COLORS::OPERATION_SUCESS;
	    }
	}
    }

  return string_to_return;
}
