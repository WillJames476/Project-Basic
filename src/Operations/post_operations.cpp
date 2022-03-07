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
		string_to_return = "opeartion done\n";
	}

	return string_to_return;
}
