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

void Users_list::add_to_list(const std::string& user_name, const std::string& user_pass,
bool is_new)
{
    this->users.insert(std::make_pair(user_name, 
    std::make_shared<Account>(user_name, user_pass)));

    if(is_new)make_new_directory(user_name);
}

void Users_list::remove_from_list(const std::string& user_name, const std::string& user_pass)
{
    auto x = this->users.find(user_name);

    if(x != this->users.end() && x->second->get_credential().second == user_pass)
    { 
        this->users.erase(x);
        std::filesystem::remove_all("users/" + user_name);
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
    (temp.get_credential().first, temp.get_credential().second, "0");
    return in;
}