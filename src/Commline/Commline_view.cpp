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

std::ostringstream Commline_view::send_as_stream () const
{
	std::ostringstream to_send_stream{};

	for(const auto& y : model_ptr->get_commlines())
	{
		to_send_stream << y.first << '\n';

		for(const auto& z : y.second->get_table())
		{
			to_send_stream << z.first << " " << std::to_string(z.second) << '\n';
		}

		to_send_stream << "END\n";
	}

	return to_send_stream;
}

void Commline_view::read_from_stream(std::istream& to_read) const
{
	std::vector<std::string> string_stack{};
	std::string extracted_string{}, account_name{};

	while(to_read >> extracted_string)
	{
		model_ptr->add_to_list(extracted_string);
		account_name = extracted_string;

		while(extracted_string != "END")
		{
			to_read >> extracted_string;

			if(extracted_string != "END")
			{
				string_stack.push_back(extracted_string);
			}

			if(string_stack.size() == 2)
			{
				model_ptr->add_to_list_acess(account_name
											, string_stack[0]
											, std::stoi(string_stack[1]));

				string_stack.erase(std::begin(string_stack)
									, std::end(string_stack));
			}
		}
	}
}
