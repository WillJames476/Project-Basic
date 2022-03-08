#include <string>
#include <vector>

#include "control_agregate.h"

std::string add_new_account(const Control_agregate& control,
							 const std::vector<std::string>& fields)
{
	std::string string_to_return{"failure\n"};

	bool is_creation_verified{control.account.add_to_list({fields[0], fields[1]})
			!= "unsuccessfull operation"};
	
	if(is_creation_verified)
	{
		control.commline.add_to_list({fields[0]});
		control.todolist.add_to_list({fields[1]});
		string_to_return = "operation done\n";
	}

	return string_to_return;
}

std::string add_new_commline(const Control_agregate& control,
							const std::vector<std::string>& fields)
{
	std::string string_to_return{"failure\n"};
	bool is_login_verified  {control.account.is_login_verified({fields[0], fields[1]})},
		 is_target_existing {control.account.is_user_existing(fields[2])};

	if(is_login_verified && is_target_existing)
	{
		control.commline.add_to_list_access({fields[0], fields[2], "0"});
		string_to_return = "operation done\n";
	}

	return string_to_return;
}

std::string add_new_task(const Control_agregate& control,
						const std::vector<std::string>& fields)
{
	std::string string_to_return{"failure\n"};

	bool is_login_verified {control.account.is_login_verified({fields[0], fields[1]})},
		 is_target_existent {control.account.is_user_existing(fields[2])};
	
	if(is_login_verified && is_target_existent)
	{
		bool is_user_permitted{control.commline.is_user_permitted({fields[0], fields[2]})};

		if(is_user_permitted)
		{
			control.todolist.add_to_list_task({fields[2], fields[0], fields[3]});
			string_to_return = "operation done\n";
		}
	}

	return string_to_return;
}
