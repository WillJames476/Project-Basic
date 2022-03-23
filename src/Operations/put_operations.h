#ifndef PUT_OPERATIONS_H
#define PUT_OPERATIONS_H

#include <string>
#include <vector>
#include <server/control_agregate.h>

std::string change_account_pasword(const Control_agregate& control,
				   const std::vector<std::string>& fields);

std::string change_commline_permission(const Control_agregate& control,
				       const std::vector<std::string>& fields);

std::string change_task_name(const Control_agregate& control,
			     const std::vector<std::string>& fields);

#endif
