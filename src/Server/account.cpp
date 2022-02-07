#include "account.h"

Account::Account(const std::string& account_name
                , const std::string& account_password)
    : account_username_string{account_name}
    , account_password_string{account_password}
{
    
}

std::string Account::get_account_password() const
{
    return  account_password_string;
}

std::string Account::get_account_username() const
{
    return  account_username_string;
}

int Account::get_field_count() const
{
    return field_count;
}

bool operator== (const Account& first, const Account& second)
{
    bool is_username_same {first.account_username_string 
                            == second.account_username_string}
        , is_password_same{first.account_password_string 
                            == second.account_password_string};

    return is_username_same && is_password_same;
}