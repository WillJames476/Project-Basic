#include <sstream>
#include <iomanip>
#include <boost/format.hpp>

#include "Commline_view.h"

std::string turn_bool_to_string(const bool to_convert)
{
	std::ostringstream to_return_string{};

	to_return_string << std::boolalpha << to_convert;

	return to_return_string.str();
}

Commline_view::Commline_view(const std::shared_ptr<Commline_model>& model)
	: model_ptr{model}
{
}

std::string Commline_view::send_formatted(const std::string& account) const
{
	std::ostringstream to_return_string{};
	const auto& permission_table{model_ptr->get_permission_table(account)};


	to_return_string << boost::format("-------------------------\n|%-10s%5s|\n")
					% "user"
					% "is permitted";

	for(const auto& entries : permission_table->get_table())
	{
		to_return_string << boost::format("|%-10s%10s|\n")
						% entries.first
						% turn_bool_to_string(entries.second);
	}

	to_return_string << "-------------------------\n";

	return to_return_string.str();
}
