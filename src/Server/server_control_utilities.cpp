#include <sstream>
#include <vector>

#include "control_agregate.h"
#include "file_agregates.h"
#include "io.h"

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

std::string apply_function(const std::string& application
                        , const std::vector<std::string>& list
                        , size_t expected_size
                        , const Control_agregate& controls
                        , std::string(*applier)
                            (const Control_agregate& ,const std::vector<std::string>&))
{
    std::string feedback{};

    if(expected_size == list.size())
    {
        if(true)
        {
            feedback = applier(controls, list);
        }
        else
        {
            feedback = invalid_argument_error(application);
        }
    }   
    else
    {
        feedback = invalid_argument_quantity_error(application, expected_size);
    }

    return feedback;
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
                        , 2, controls 
                        , [](const auto& x, const auto& y)
                            {return x.account.get_from_list({y[0], y[1]});});
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
                        , 2, controls 
                        , [](const auto& x, const auto& y)
                            {return x.account.add_to_list({y[0], y[1]});});
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
                        , 2, controls 
                        , [](const auto& x, const auto& y)
                            {return x.account.remove_from_list({y[0], y[1]});});
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