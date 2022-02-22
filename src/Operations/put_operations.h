#ifndef PUT_OPERATIONS_H
#define PUT_OPERATIONS_H

#include <string>
#include <vector>
#include "Control_agregate.h"

namespace put_operation
{
	std::string change_account_pasword(const Control_agregate& control
									, const std::vector<std::string>& fields);

	std::string change_commline_permission(const Control_agregate& control
										, const std::vector<std::string>& fields);

	std::string change_task_nam(const Control_agregate& control
							 , const std::vector<std::string>& fields);
}

#endif
