#ifndef POST_OPERATIONS_H
#define POST_OPERATIONS_H

#include <vector>
#include <string>
#include "Control_agregate.h"

namespace post_operations
{
	std::string add_new_account(const Control_agregate& control
								, const std::vector<std::string>& fields);

	std::string add_new_commline(const Control_agregate& control
								, const std::vector<std::string>& fields);

	std::string add_new_task(const Control_agregate& control
							, const std::vector<std::string>& fields);
}

#endif
