#include <string>
#include <vector>

#include "control_agregate.h"

std::string create_new_account(const Control_agregate& control,
							 const std::vector<std::string>& fields)
{
	std::string string_to_return;

	control.account.add_to_list({fields[0], fields[1]});

	return string_to_return;
}
