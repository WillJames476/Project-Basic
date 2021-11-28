#include "Account.h"

Account::Account(const std::string& user_name, const std::string& user_pass)
: credentials(std::make_pair(user_name, user_pass))
{

}

std::pair<std::string, std::string> Account::get_credential()
{
    return this->credentials;
}