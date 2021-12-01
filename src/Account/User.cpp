#include "User.h"

User::User(const std::pair<std::string, std::string>& credentials)
:account(credentials), lines({credentials.first})
{
    
}

std::pair<std::string, std::string> User::get_credential() const
{
    return this->account.get_credential();
}

std::vector<std::string> User::get_lines() const
{
    return this->lines.get_communication_lines();
}
