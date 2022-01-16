#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <array>

#include "Users_list.h"
#include "../includes/io.h"

void make_new_directory(const std::string& user_name)
{
    std::filesystem::create_directory("users/"+ user_name);
}

void Users_list::add_item(const std::initializer_list<std::string>& datas)
{
    int tracker = 0;
    std::array<std::string, 3> retrieved_datas;
    
    for(const auto&x : datas)
    {
        retrieved_datas[tracker++] = x;
    }

    this->users.insert(std::make_pair(retrieved_datas[0], 
    std::make_shared<Account>(retrieved_datas[0], retrieved_datas[1])));

    if(std::stoi(retrieved_datas[2]))
    {
        make_new_directory(retrieved_datas[0]);
    }
}

void Users_list::remove_item(const Account& to_remove)
{
    auto credential = to_remove.get_credential();
    auto location = users.find(credential.first);

    if(location != users.end() && 
    credential.second == location->second->get_credential().second)
    {
        users.erase(location);
        std::filesystem::remove_all("users/" + credential.first);
    }
}

Account Users_list::get_item(const Account& to_get)
{
    auto credentials = to_get.get_credential();
    auto location = users.find(credentials.first);

    if(location != users.end())
    {
        location->second->get_credential().second == credentials.second;
        return *location->second;
    }
    return Account{};
}

std::ostream& operator<<(std::ostream& out, const Users_list& user)  
{
    for(const auto& to_give : user.users) out << *to_give.second;
    return out;
}

std::istream& operator>>(std::istream& in, Users_list& user)
{
    Account temp{};
    while(in >> temp)user.add_to_list
    ({temp.get_credential().first, temp.get_credential().second, "0"});
    return in;
}