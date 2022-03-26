#ifndef DELETE_OPERATIONS_H
#define DELETE_OPERATIONS_H

#include <string>
#include <vector>
#include <agregates/control_agregate.h>

std::string
delete_account(const Control_agregate& control,
	       const std::vector<std::string>& fields);

std::string
delete_a_line(const Control_agregate& control,
	      const std::vector<std::string>& fields);

std::string
delete_a_task(const Control_agregate& control,
	      const std::vector<std::string>& fields);

#endif
