#include <sstream>
#include <boost/format.hpp>

#include "Todolist_view.h"

Todolist_view::Todolist_view(const std::shared_ptr<Todolist_model>& model)
	: model_ptr{model}
{
}

std::string Todolist_view::send_formatted(const std::string& account_name) const
{
	std::ostringstream to_return_string {};
	const auto& task_list               {model_ptr->get_item_from_list(account_name)};

	to_return_string << boost::format("|%-20s%10s|\n")
					% "task name"
					% "task giver";

	for(const auto& task : task_list)
	{
		to_return_string << boost::format("|%-20s%10s|\n")
						% task.task_name_str
						% task.task_giver_str;
	}

	return to_return_string.str();
}
