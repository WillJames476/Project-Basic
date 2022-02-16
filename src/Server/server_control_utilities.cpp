#include <sstream>
#include <vector>

#include "control_agregate.h"
#include "file_agregates.h"
#include "server_control_utilities.h"
#include "view_agregate.h"

namespace ARGS_REGEX
{
    using namespace REGEX_PREDICATES;

    std::initializer_list<std::regex>
        ACCOUNT    {ALPHA_NOSPACE, ALPHA_NOSPACE}
        , COMMLINE {ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE}
		, TASK     {ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE_S};
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

std::string get_control(std::istringstream& message
					   , const View_agregate& view
					   , const Control_agregate& control)
{
    std::string application{};
    message >> application;
	auto args{extract_args(message)};

    if(application == "--account")
    {
		application = apply_function(application, args
									, ARGS_REGEX::ACCOUNT
									, 2, view
									, [&](const auto& x, const auto& y)
										{
											bool is_user_verified{control.account.get_from_list({y[0], y[1]})
													!= "unsuccessfull operation"};

											return is_user_verified ?
													x.account.send_formatted(y[0])
													: std::string{"failure"};
										});
    }
    else if(application == "--commline")
    {
		application = apply_function(application, args
									, ARGS_REGEX::ACCOUNT
									, 2 , view
									, [&](const auto& x, const auto& y)
										{
											bool is_user_verified{control.account.get_from_list({y[0], y[1]})
													!= "unsuccessfull operation"};

											return is_user_verified ?
													x.commline.send_formatted(y[0])
													: std::string{"failure"};
										});
    }
    else if(application == "-- todolist")
    {
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
        application = apply_function(application, args
                        , ARGS_REGEX::ACCOUNT
                        , 2, controls 
                        , [](const auto& x, const auto& y)
                            {
                                std::string feedback_string
                                        {x.account.add_to_list({y[0], y[1]})};
                                bool is_register_verified{feedback_string 
                                    == "succesfull operation"};

                                    if(is_register_verified)
                                    {
                                        x.commline.add_to_list({y[0]});
                                        x.todolist.add_to_list({y[0]});
                                    }

                                return feedback_string;
                            });
    }
    else if(application == "--commline")
    {
        application = apply_function(application, args
                        , ARGS_REGEX::COMMLINE
                        , 3 ,controls
                        , [](const auto& x, const auto& y)
                            {
                                bool is_loged_in{x.account.get_from_list({y[0], y[1]}) 
                                        != "unsuccessfull operation"}
                                    , is_user_existing{x.account.is_user_existing(y[2])};

                                return is_loged_in && is_user_existing ?
                                    x.commline.add_to_list_access({y[0], y[2], "0"})
                                    : std::string{"failure"};
                            });
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
												, is_user_existing  {x.account.is_user_existing(y[2])}
												, is_user_permitted {x.commline.is_user_permitted
																		({y[0], y[2]})};

											return is_loged_in && is_user_existing && is_user_permitted ?
													x.todolist.add_to_list_task({y[0], y[3] , y[2]})
													: std::string{"fialure"};
										});
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
                        , [](const auto& x, const auto& y)
                            {
                                std::string operation_output
                                    {x.account.remove_from_list({y[0], y[1]})};
                                bool is_deletion_successfull{operation_output 
                                        == "succesfull operation"};

                                    if(is_deletion_successfull)
                                    {
                                        x.commline.remove_from_list({y[0]});
                                        x.todolist.remove_from_list({y[0]});
                                    }

                                return operation_output;
                            });
    }
    else if(application == "--commline")
    {
        application = apply_function(application, args
                        , ARGS_REGEX::COMMLINE
                        , 3 ,controls
                        , [](const auto& x, const auto& y)
                            {
                                bool is_loged_in{x.account.get_from_list({y[0], y[1]}) 
                                        != "unsuccessfull operation"};

                                return is_loged_in ?
                                    x.commline.remove_from_list_access({y[0], y[2], "0"})
                                    : std::string{"failure"};
                            });
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
                        , ARGS_REGEX::COMMLINE
                        , 3, controls
                        , [](const auto& x, const auto& y)
                            {
                                bool is_logged_in{x.account.get_from_list({y[0], y[1]})
                                        != "unsuccessfull operation"}
                                    , is_user_existing{x.account.is_user_existing(y[2])};

                                return is_logged_in && is_user_existing ? 
                                    x.commline.modify_permission({y[0], y[2]}) 
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
