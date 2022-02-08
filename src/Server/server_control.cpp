#include <string>
#include <sstream>
#include <iostream>
#include <functional>

#include "generic_view.h"
#include "generic_file.h"
#include "model_agregate.h"
#include "control_agregate.h"

std::string get_control(const std::string& message
                , const Control_agregate& controls);

std::string put_control(const std::string& message
                    , const Control_agregate& controls);

std::string delete_control(const std::string& message
                    , const Control_agregate& controls);

std::string server_control(const std::string& message)
{
    Model_agregate models{};
    Control_agregate controls{models};

    std::istringstream method_extract(message);
    std::string method{}, to_return{message}, post_extract{};

    method_extract >> method;
    post_extract = method_extract.str();

    if(method == "GET")
    {
        to_return = get_control(post_extract, controls);
    }
    else if(method == "PUT")
    {
        to_return = put_control(post_extract, controls);
    }
    else if(method == "DELETE")
    {
        to_return = delete_control(post_extract, controls);
    }

    return to_return;
}

std::string get_control(const std::string& message
                , const Control_agregate& controls)
{
    std::string application{};
    std::istringstream arguments(message);

    arguments >> application >> application;

    if(application == "--account")
    {
        application = controls.account.add_to_list({"hello", "hi"});
    }

    return application;
}

std::string put_control(const std::string& message
                        , const Control_agregate& controls)
{
    std::string application{};
    std::istringstream arguments(message);

    arguments >> application >> application;

    if(application == "--account")
    {
        application = controls.account.get_from_list({"hello", "hi"});
    }

    return application;
}

std::string delete_control(const std::string& message
                        , const Control_agregate& controls)
{
    std::string application{};
    std::istringstream arguments(message);

    arguments >> application >> application;

    if(application == "--account")
    {
        application = controls.account.remove_from_list({"hello","hi"});
    }

    return application;
}

void file_control(const std::string& mode)
{
    if(mode == "READ")
    {

    }
    else if(mode == "WRITE")
    {
        
    }
}