#include "User.h"

User::User(const std::string& account_name, const std::string& account_pass)
:account(account_name, account_pass)
{
    
}

bool User::is_same_credential(const std::string& account_name, 
const std::string& account_pass)
{
    auto x = this->account.get_credential();
    return x.first == account_name && x.second == account_pass;
}

std::pair<std::string, std::string> User::get_credential()
{
    return this->account.get_credential();
}