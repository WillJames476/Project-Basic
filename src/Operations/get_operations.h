#ifndef GT_OPERATIONS_H
#define GET_OPERATIONS_H

#include <vector>
#include <string>
#include "control_agregate.h"
#include "view_agregate.h"

namespace get_operation
{
	std::string get_account_info(const View_agregate& view
								, const Control_agregate& control
								, const std::vector<std::string>& fields);

	std::string get_commline_table(const View_agregate& view
								, const Control_agregate& control
								, const std::vector<std::string& fields>);

	std::string get_todolist_list(const View_agregate& view
								, const Control_agregate& control
								, const std::vector<std::string>& fields);
}

#endif
