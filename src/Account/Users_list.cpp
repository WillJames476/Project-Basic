#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>

#include "Users_list.h"
#include "../Utilities/io.h"

void make_new_directory(const std::string& user_name)
{
    std::filesystem::create_directory("users/"+ user_name);
}

void Users_list::add_to_list(const std::initializer_list<std::string>& credentials)
{
    std::vector<std::string> data;
    for(auto s : credentials)data.push_back(s);

    this->users.insert
    (std::make_pair(data[0], std::make_shared<Account>(data[0], data[1])));

    if(std::stoi(data[2]))make_new_directory(data[0]);
}

void Users_list::remove_from_list(const std::initializer_list<std::string>& credentials)
{
    std::vector<std::string> data;
    for(auto s : credentials)data.push_back(s);
    auto x = this->users.find(data[0]);

    if(x != this->users.end() && x->second->get_credential().second == data[1])
    { 
        this->users.erase(x);
        std::filesystem::remove_all("users/" + data[0]);
    }
}


std::string Users_list::account_login(const std::string& account_name, 
const std::string &account_password) const
{
    auto z = this->users.find(account_name);

    if(z!= this->users.end() && 
    z->second->get_credential().second == account_password) 
    return z->first;
    return {};
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