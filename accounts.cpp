#include "accounts.h"
#include <fstream>

void Accounts::new_account(const std::string& account_name, const std::string &account_password, const bool is_new)
{
    accounts.emplace(std::make_pair(account_name, account_password));

    if(is_new)make_new_file(account_name);
}

std::string Accounts::account_login(const std::string& account_name, const std::string &account_password)
{
    std::map<std::string ,std::string>::iterator z = accounts.find(account_name);

    if(z!= accounts.end() && z->second == account_password) return "users/"+ z->first +".txt";
    return NULL;
}

void Accounts::make_new_file(const std::string& account_name)
{
    std::ofstream file_to_make("users/" + account_name + ".txt");
    file_to_make.close();
}

void Accounts::load_accounts_from_file(const std::string& accounts_file)
{
    std::ifstream file_to_read(accounts_file);
    std::string user_name_accumulator, password_accumulator;

    while(file_to_read >> user_name_accumulator >> password_accumulator)
    {
        new_account(user_name_accumulator, password_accumulator, false);
    }

    file_to_read.close();
}

void Accounts::save_accounts_to_a_file(const std::string& accounts_file)
{
    std::ofstream file_archiver(accounts_file);
    std::string string_to_give_to_file;

    for(auto z : accounts)
    {
        string_to_give_to_file += z.first + " " + z.second + "\n";
    }

    file_archiver << string_to_give_to_file;

    file_archiver.close();
}