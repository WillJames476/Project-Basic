#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>

#include "Users_list.h"
#include "User.h"
#include "../Utilities/io.h"

void make_new_file(const std::string& account_name)
{
    std::ofstream file_to_make("users/" + account_name + ".csv");
    file_to_make.close();
}

void Users_list::new_account(const std::string& account_name, 
const std::string &account_password)
{
    this->users.insert
    (std::make_pair(account_name, std::make_shared<User>
    (std::make_pair(account_name,account_password))));
    make_new_file(account_name);
}

void Users_list::new_account(const std::string& account_name, 
const std::string &account_password, 
const std::vector<std::string>& lines)
{
    this->users.insert
    (std::make_pair(account_name, std::make_shared<User>
    (std::make_pair(account_name,account_password),lines)));
}


void Users_list::remove_account(const std::string& account_name, 
const std::string &account_password)
{
    auto x = this->users.find(account_name);

    if(x->second->get_credential().second == account_password) 
    this->users.erase(x);

    std::filesystem::remove("users/" + account_name + ".csv");
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

void Users_list::add_communication_line(const std::string& user_name)
{
    auto x = this->users.find(user_name);
    
    if(x != this->users.end())x->second->add_communication_line(user_name);
}

void Users_list::print_communication_line(const std::string& user_name)
{
    auto x = this->users.find(user_name);

    if(x != this->users.end())
    {
        auto z = x->second->get_lines();
        std::ostringstream accessibles;
        for(auto y : z)accessibles << y << '\n';
        std::cout << accessibles.str();
    }
}

std::vector<std::string> Users_list::get_communication_line(const std::string& user_name) const
{
    auto x = this->users.find(user_name);
    
    if(x != this->users.end())return x->second->get_lines();
    return std::vector<std::string>();
}

void Users_list::load_from_file(const std::string& accounts_file)
{
    std::ifstream file_to_read(accounts_file);
    std::string user_name_accumulator, password_accumulator, line_accumulator,
    communication_lines_accumulator;

    while(std::getline(file_to_read, line_accumulator))
    {
        replace_char_with(line_accumulator,',', ' ');
        std::istringstream(line_accumulator) >> user_name_accumulator 
        >> password_accumulator >> communication_lines_accumulator;
        new_account(user_name_accumulator, password_accumulator,
        string_to_list<std::string>(communication_lines_accumulator, '-'));
    }

    file_to_read.close();
}

void Users_list::save_to_file(const std::string& accounts_file)
{
    std::ofstream file_archiver(accounts_file);
    std::string string_to_give_to_file;

    for(auto z : this->users)
    {
        auto x = z.second->get_credential();
        string_to_give_to_file += x.first + "," + x.second
         + "," 
         + vector_to_string<std::string>
         (z.second->get_lines(), '-') +"\n";
    }

    file_archiver << string_to_give_to_file;
    file_archiver.close();
}