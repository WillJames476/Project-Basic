#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>

#include "Users_list.h"
#include "../Utilities/io.h"

void make_new_file(const std::string& account_name)
{
    std::ofstream file_to_make("users/" + account_name + ".csv");
    file_to_make.close();
}

void Users_list::add_to_list(const std::initializer_list<std::string>& credentials)
{
    std::vector<std::string> data;
    for(auto s : credentials)data.push_back(s);

    this->users.insert
    (std::make_pair(data[0], std::make_shared<Account>
    (std::make_pair(data[0], data[1]))));
    make_new_file(data[0]);
}

void Users_list::remove_from_list(const std::initializer_list<std::string>& credentials)
{
    std::vector<std::string> data;
    for(auto s : credentials)data.push_back(s);
    auto x = this->users.find(data[0]);
    if(x->second->get_credential().second == data[1]) this->users.erase(x);
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
    std::ifstream file_to_read(accounts_file);
    std::string user_name_accumulator, password_accumulator, line_accumulator,
    communication_lines_accumulator;

    while(std::getline(file_to_read, line_accumulator))
    {
        replace_char_with(line_accumulator,',', ' ');
        std::istringstream(line_accumulator) >> user_name_accumulator 
        >> password_accumulator >> communication_lines_accumulator;

        add_to_list({user_name_accumulator, password_accumulator});
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
        string_to_give_to_file += x.first + "," + x.second +"\n";
    }

    file_archiver << string_to_give_to_file;
    file_archiver.close();
}
