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

std::ostringstream Todolist_view::send_as_stream() const
{
	std::ostringstream to_return_stream{};

	for(const auto& z : model_ptr->get_tasks())
	{
		to_return_stream << z.first << '\n';

		for(const auto& y : z.second)
		{
			to_return_stream << y.task_name_str << " " << y.task_giver_str << '\n';
		}

		to_return_stream << "END\n";
	}

	return to_return_stream;
}

void Todolist_view::read_from_stream(std::istream& to_read) const
{
	std::string account_name	 {},
				extracted_string {};
	std::vector<std::string> string_stack {};

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
				model_ptr->add_to_list_task(account_name
									, string_stack[0]
									, string_stack[1]);

				string_stack.erase(std::begin(string_stack)
									, std::end(string_stack));
			}
		}
	}
}
