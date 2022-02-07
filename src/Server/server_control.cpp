#include <string>
#include <sstream>
#include <iostream>

void post_control(const std::string& message);
void get_control(const std::string& message);
void put_control(const std::string& message);
void delete_control(const std::string& message);
void patch_control(const std::string& message);

std::string server_control(const std::string& message)
{
    std::istringstream method_extract(message);
    std::string method{}, to_return{}, post_extract{};

    method_extract >> method;
    post_extract = method_extract.str();

    if(method == "GET")
    {
        get_control(post_extract);
    }
    else if(method == "POST")
    {
        post_control(post_extract);
    }
    else if(method == "PUT")
    {
        put_control(post_extract);
    }
    else if(method == "DELETE")
    {
        delete_control(post_extract);
    }
    else if(method == "PATCH")
    {
        patch_control(post_extract);
    }

    return to_return;
}

void post_control(const std::string& message)
{
    std::cout << message;
}

void get_control(const std::string& message)
{
    std::cout << message;
}

void put_control(const std::string& message)
{
    std::cout << message;
}

void delete_control(const std::string& message)
{
    std::cout << message;
}

void patch_control(const std::string& message)
{
    std::cout << message;
}