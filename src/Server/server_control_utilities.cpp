#include <sstream>
#include <vector>

#include "control_agregate.h"
#include "file_agregates.h"
#include "server_control_utilities.h"

namespace ARGS_REGEX
{
    using namespace REGEX_PREDICATES;

    std::initializer_list<std::regex>
        ACCOUNT{ALPHA_NOSPACE, ALPHA_NOSPACE},
        COMMLINE{ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE};
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
                            {return x.account.get_from_list({y[0], y[1]});});
    }
    else if(application == "--commline")
    {

    }

    return application;
}

std::string put_control(std::istringstream& message
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
                                x.commline.add_to_list({y[0]});
                                return x.account.add_to_list({y[0], y[1]});
                            });
    }
    else if(application == "--commline")
    {
        application = apply_function(application, args
                        , ARGS_REGEX::COMMLINE
                        , 3 ,controls
                        , [](const auto& x, const auto& y)
                            {
                                std::string to_return_str{};

                                bool is_loged_in{x.account.get_from_list({y[0], y[1]}) 
                                    != "unsuccessfull operation"}
                                    , is_user_existing{x.account.is_user_existing(y[2])};

                                if(is_loged_in && is_user_existing)
                                {
                                    to_return_str = x.commline.add_to_list_access({y[0],y[2], "0"});
                                }

                                return to_return_str;
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
                                x.commline.remove_from_list({y[0]});
                                return x.account.remove_from_list({y[0], y[1]});
                            });
    }
    else if(application == "--commline")
    {
        application = apply_function(application, args
                        , ARGS_REGEX::COMMLINE
                        , 3 ,controls
                        , [](const auto& x, const auto& y)
                            {
                                std::string to_return_str{};
                                bool is_loged_in{x.account.get_from_list({y[0], y[1]}) 
                                    != "unsuccessfull operation"};

                                if(is_loged_in)
                                {
                                    to_return_str = x.commline.remove_from_list_access({y[0],y[2], "0"});
                                }

                                return to_return_str;
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