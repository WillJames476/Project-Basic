#include "Account.h"

Account::Account(const std::string& user_name, const std::string& user_pass)
: credentials{std::make_pair(user_name, user_pass)}
{

}

Account::Account(const std::pair<std::string, std::string>& creds)
: credentials{creds}
{

}
std::pair<std::string, std::string> Account::get_credential() const
{
    return this->credentials;
}