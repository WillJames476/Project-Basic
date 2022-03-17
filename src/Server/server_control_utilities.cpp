#include <sstream>
#include <vector>

#include "control_agregate.h"
#include "file_agregates.h"
#include "server_control_utilities.h"
#include "view_agregate.h"

#include "../Operations/post_operations.h"
#include "../Operations/delete_operations.h"
#include "../Operations/get_operations.h"

namespace ARGS_REGEX
{
    using namespace REGEX_PREDICATES;

    std::initializer_list<std::regex>
        ACCOUNT        {ALPHA_NOSPACE, ALPHA_NOSPACE}
        , COMMLINE     {ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE}
	, COMMLINE_PUT {ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE, BOOLEAN}
	, TASK         {ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE_S};
}

std::vector<std::string> extract_args(std::istringstream& message)
{
    std::vector<std::string> to_return;
    std::string holder{};

    while(message >> holder)
    {
        to_return.push_back(holder);
    }

    return to_return;
}

std::string get_control(std::istringstream& message,
			const View_agregate& view,
			const Control_agregate& control)
{
    std::string application{};
    message >> application;
    auto args{extract_args(message)};

    if(application == "--account")
      {
	application = apply_function(application, args,
				     ARGS_REGEX::ACCOUNT,
				     2, view,
				     [&](const auto& x, const auto& y)
				     {return get_account_info(x, control, y);});
      }
    else if(application == "--commline")
      {
	application = apply_function(application, args,
				     ARGS_REGEX::ACCOUNT,
				     2 , view,
				     [&](const auto& x, const auto& y)
				     {return get_commline_table(x, control,y);});
      }
    else if(application == "--todolist")
      {
	application = apply_function(application, args,
				     ARGS_REGEX::ACCOUNT,
				     2 , view,
				     [&](const auto& x, const auto& y)
										{
											bool is_user_verified{control.account.get_from_list({y[0], y[1]})
													!= "unsuccessfull operation"};

											return is_user_verified ?
													x.todolist.send_formatted(y[0])
													: std::string{"failure"};
										});
    }

    return application;
}

std::string post_control(std::istringstream& message
                        , const Control_agregate& controls)
{
    std::string application{};
    message >> application;
    auto args{extract_args(message)};

    if(application == "--account")
      {
        application = apply_function(application, args,
				     ARGS_REGEX::ACCOUNT,
				     2, controls ,
				     [](const auto& x, const auto& y){return add_new_account(x, y);});
      }
    else if(application == "--commline")
      {
        application = apply_function(application, args,
				     ARGS_REGEX::COMMLINE,
				     3 ,controls,
				     [](const auto& x, const auto& y){return add_new_commline(x, y);});
      }
    else if(application == "--todolist")
      {
	application = apply_function(application, args,
				     ARGS_REGEX::TASK,
				     4, controls,
				     [](const auto& x, const auto& y){return add_new_task(x, y);});
      }

    return application;
}

std::string delete_control(std::istringstream& message
                        , const Control_agregate& controls)
{
    std::string application{};
    message >> application;
    auto args{extract_args(message)};

    if(application == "--account")
    {
        application = apply_function(application, args
                        , ARGS_REGEX::ACCOUNT  
                        , 2, controls 
                        , [](const auto& x, const auto& y){return delete_account(x, y);});
    }
    else if(application == "--commline")
    {
        application = apply_function(application, args
                        , ARGS_REGEX::COMMLINE
                        , 3 ,controls
                        , [](const auto& x, const auto& y){return delete_a_line(x, y);});
    }
	else if(application == "--todolist")
	{
		application = apply_function(application, args
									, ARGS_REGEX::TASK
									, 4, controls
									, [](const auto& x, const auto& y)
										{
											bool is_loged_in{x.account.get_from_list({y[0], y[1]})
													!= "unsuccessfull operation"}
												, is_permitted{x.commline.is_user_permitted({y[0], y[2]})};

											return is_loged_in && is_permitted ?
												x.todolist.remove_from_list_task({y[0], y[3], y[2]})
												: std::string{};
										});
	}

    return application;
}

std::string put_control(std::istringstream& message
                        , const Control_agregate& controls)
{
    std::string application{};
    message >> application;
    auto args{extract_args(message)};

    if(application == "--commline")
    {
        application = apply_function(application, args
                        , ARGS_REGEX::COMMLINE_PUT
                        , 4, controls
                        , [](const auto& x, const auto& y)
                            {
                                bool is_logged_in{x.account.get_from_list({y[0], y[1]})
                                        != "unsuccessfull operation"}
                                    , is_user_existing{x.account.is_user_existing(y[2])};

                                return is_logged_in && is_user_existing ?
                                    x.commline.modify_permission({y[0], y[2], y[3]}) 
                                    : "fail";
                            });
    }

    return application;
}

void file_control(const std::string& mode
                , File_agregate& file)
{
    if(mode == "READ")
      {
	file.read_all();
      }
    else if(mode == "WRITE")
      {
	file.save_all();
      }
}
