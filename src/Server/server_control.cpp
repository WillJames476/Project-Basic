#include <string>
#include <sstream>
#include <iostream>
#include <functional>

#include "generic_view.h"
#include "generic_file.h"

void get_control(const std::string& message);
void put_control(const std::string& message);
void delete_control(const std::string& message);

std::string server_control(const std::string& message)
{
    std::istringstream method_extract(message);
    std::string method{}, to_return{message}, post_extract{};

    method_extract >> method;
    post_extract = method_extract.str();

    if(method == "GET")
    {
        get_control(post_extract);
    }
    else if(method == "PUT")
    {
        put_control(post_extract);
    }
    else if(method == "DELETE")
    {
        delete_control(post_extract);
    }

    return to_return;
}

void get_control(const std::string& message)
{
    if(message == "NULL")
    {

    }
}

void put_control(const std::string& message)
{
    std::string application{};
    std::istringstream arguments(message);

    arguments >> application;

    if(application == "--account")
    {
        std::cout << arguments.str();
    }
}

void delete_control(const std::string& message)
{
    if(message == "NULL")
    {

    }
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