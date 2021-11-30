#include "User.h"

User::User(const std::pair<std::string, std::string>& credentials)
:account(credentials), lines({credentials.first})
{
    
}

User::User(const std::pair<std::string, std::string>& credentials, 
const std::initializer_list<std::string>& fields)
:account(credentials.first, credentials.second),lines(fields)
{

}

User::User(const std::pair<std::string, std::string>& credentials, 
const std::vector<std::string>& fields)
:account(credentials.first, credentials.second),lines(fields)
{

}

bool User::is_same_credential(const std::string& account_name, 
const std::string& account_pass)
{
    auto x = this->account.get_credential();
    return x.first == account_name && x.second == account_pass;
}

std::pair<std::string, std::string> User::get_credential() const
{
    return this->account.get_credential();
}

std::vector<std::string> User::get_lines() const
{
    return this->lines.get_communication_lines();
}

void User::add_communication_line(const std::string& user_name)
{
    this->lines.add_to_list(user_name);
}