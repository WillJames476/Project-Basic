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
    (std::make_pair(data[0], std::make_shared<Account>
    (std::make_pair(data[0], data[1]))));

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

void Users_list::load_from_file(const std::string& accounts_file)
{
    try
    {
        std::fstream file_to_read(accounts_file, std::ios_base::in);
        std::string user_name_accumulator, password_accumulator;

        while(file_to_read >> user_name_accumulator >> password_accumulator)
        {
            add_to_list({user_name_accumulator, password_accumulator, "0"});
        }

        file_to_read.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void Users_list::save_to_file(const std::string& accounts_file)
{
    try
    {
        std::fstream file_archiver(accounts_file, std::ios_base::out);
        std::string string_to_give_to_file;

        for(const auto& z : this->users)
        {
            auto x = z.second->get_credential();
            string_to_give_to_file += x.first + " " + x.second +"\n";
        }

        file_archiver << string_to_give_to_file;
        file_archiver.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}