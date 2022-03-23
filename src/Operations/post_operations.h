#ifndef POST_OPERATIONS_H
#define POST_OPERATIONS_H

#include <vector>
#include <string>
#include <server/control_agregate.h>

std::string add_new_account(const Control_agregate& control,
			    const std::vector<std::string>& fields);

std::string add_new_commline(const Control_agregate& control,
			     const std::vector<std::string>& fields);

std::string add_new_task(const Control_agregate& control,
			 const std::vector<std::string>& fields);

#endif
