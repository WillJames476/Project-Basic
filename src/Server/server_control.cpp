#include <string>
#include <sstream>
#include <iostream>
#include <functional>

#include "generic_view.h"
#include "generic_file.h"
#include "model_agregate.h"
#include "control_agregate.h"
#include "file_agregates.h"


std::string get_control(std::istringstream& message
                , const Control_agregate& controls);

std::string put_control(std::istringstream& message
                    , const Control_agregate& controls);

std::string delete_control(std::istringstream& message
                    , const Control_agregate& controls);

void file_control(const std::string& mode
                , File_agregate& file);

std::string apply_function(const std::vector<std::string>& list
                        , size_t expected_size
                        , const Control_agregate& controls
                        , std::string(*applier)
                            (const Control_agregate& ,const std::vector<std::string>&));

std::vector<std::string> extract_args(std::istringstream& message);

std::string server_control(const std::string& message)
{
    Model_agregate models{};
    Control_agregate controls{models};
    File_agregate files{models};

    file_control("READ", files);

    std::istringstream method_extract(message);
    std::string method{}, to_return{message};
    method_extract >> method;

    if(method == "GET")
    {
        to_return = get_control(method_extract, controls);
    }
    else if(method == "PUT")
    {
        to_return = put_control(method_extract, controls);
    }
    else if(method == "DELETE")
    {
        to_return = delete_control(method_extract, controls);
    }

    file_control("WRITE", files);

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
        application = apply_function(args , 2
                        , controls , [](const auto& x, const auto& y)
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
        application = apply_function(args , 2
                        , controls , [](const auto& x, const auto& y)
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
        application = apply_function(args , 2
                        , controls , [](const auto& x, const auto& y)
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

std::string apply_function(const std::vector<std::string>& list
                        , size_t expected_size
                        , const Control_agregate& controls
                        , std::string(*applier)
                            (const Control_agregate& ,const std::vector<std::string>&))
{
    std::string feedback{};

    if(expected_size == list.size())
    {
        feedback = applier(controls, list);
    }   
    else
    {
        feedback = "argument count not met\n";
    }

    return feedback;
}