#include <sstream>
#include <vector>

#include "../includes/file_agregates.h"

File_agregate::File_agregate(const Model_agregate& models)
        : account{Generic_file_s<Account_view>{models.account, "data/accounts.txt"}}
        , commline{Generic_file<Commline_model>{models.commline, "data/commline.txt"}}
        , todolist{Generic_file<Todolist_model>{models.todolist, "data/todolist.txt"}}
{
}

void File_agregate::save_all()
{ 
	auto commline_write{[](auto& x)
        {
            std::ostringstream to_return{};

            for(const auto& y : x->get_commlines())
            {
                to_return << y.first << '\n';

                for(const auto& z : y.second->get_table())
                {
                    to_return << z.first << " " << std::to_string(z.second) << '\n';
                }

                to_return << "END\n";
            }

            return to_return.str();
        }};

    auto todolist_write{[](auto& x)
        {
            std::ostringstream to_return{};

            for(const auto& z : x->get_tasks())
            {
                to_return << z.first << '\n';

                for(const auto& y : z.second)
                {
                    to_return << y.task_name_str << " " << y.task_giver_str << '\n';
                }

                to_return << "END\n";
            }

            return to_return.str();
        }};

    account.save_file();
    save_file(commline, commline_write);
    save_file(todolist, todolist_write);
}

void File_agregate::read_all()
{
    auto commline_read{[](auto& x, auto& y)
        {
            std::vector<std::string> string_stack{};
            std::string extracted_string{}, account_name{};

            while(x >> extracted_string)
            {
                y->add_to_list(extracted_string);
                account_name = extracted_string;

                while(extracted_string != "END")
                {
                    x >> extracted_string;
                    
                    if(extracted_string != "END")
                    {
                        string_stack.push_back(extracted_string);
                    }

                    if(string_stack.size() == 2)
                    {
                        y->add_to_list_acess(account_name
                                            , string_stack[0]
                                            , std::stoi(string_stack[1]));

                        string_stack.erase(std::begin(string_stack)
                                        , std::end(string_stack));
                    }
                }
            }
        }};

    auto todolist_read{[](auto& x, auto& y)
        {
            std::string 			  account_name     {}
									, extracted_string {};
			std::vector<std::string>  string_stack     {};			

            while(x >> extracted_string)
            {
                y->add_to_list(extracted_string);
				account_name = extracted_string;

                while(extracted_string != "END")
                {
                    x >> extracted_string;

					if(extracted_string != "END")
					{
						string_stack.push_back(extracted_string);
					}

					if(string_stack.size() == 2)
					{
						y->add_to_list_task(account_name
											, string_stack[0]
											, string_stack[1]);

						string_stack.erase(std::begin(string_stack)
										, std::end(string_stack));
					}
				}
            }
        }};

    account.read_file();
    read_file(commline, commline_read);
    read_file(todolist, todolist_read);
}   
