#ifndef GT_OPERATIONS_H
#define GET_OPERATIONS_H

#include <string>
#include "control_agregate.h"
#include "view_agregate.h"

std::string get_account_formatted(const View_agregate& view
							, const Control_agregate& control
							, const std::vector<std::string>& fields);

std::string get_commline_formatted(const View_agregate& view
								, const Control_agregate& control
								, const std::vector<std::string& fields>);

std::string get_todolist_formatted(const View_agregate& view
								, const Control_agregate& control
								, const std::vector<std::string>& fields);

#endif
