#include <fstream>
#include <iostream>
#include <filesystem>

#include "Users_list.h"
#include "User.h"
#include "io.h"

void make_new_file(const std::string& account_name)
{
    std::ofstream file_to_make("users/" + account_name + ".csv");
    file_to_make.close();
}

void Users_list::new_account(const std::string& account_name, 
const std::string &account_password, const bool is_new)
{
    this->users.insert
    (std::make_pair(account_name, std::make_shared<User>
    (std::make_pair(account_name,account_password))));

    if(is_new)make_new_file(account_name);
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
    return "users/"+ z->first +".csv";
    return {};
}


void Users_list::load_accounts_from_file(const std::string& accounts_file)
{
    std::ifstream file_to_read(accounts_file);
    std::string user_name_accumulator, password_accumulator, line_accumulator;

    while(std::getline(file_to_read, line_accumulator))
    {
        replace_char_with(line_accumulator,',', ' ');
        std::istringstream(line_accumulator) >> user_name_accumulator 
        >> password_accumulator;
        new_account(user_name_accumulator, password_accumulator, false);
    }

    file_to_read.close();
}

void Users_list::save_accounts_to_a_file(const std::string& accounts_file)
{
    std::ofstream file_archiver(accounts_file);
    std::string string_to_give_to_file;

    for(auto z : this->users)
    {
        auto x = z.second->get_credential();
        string_to_give_to_file += x.first + "," + x.second + "\n";
    }

    file_archiver << string_to_give_to_file;
    file_archiver.close();
}