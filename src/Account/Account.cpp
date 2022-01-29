#include <array>

#include "Account.h"

Account::Account()
{

}

Account::Account(const std::string& user_name
                , const std::string& user_pass)
    : credentials{std::make_pair(user_name, user_pass)}
{
}

std::pair<std::string, std::string> Account::get_credential() const
{
    return this->credentials;
}

std::ostream& operator<<(std::ostream& out
                        , const Account& account)
{
    out << account.credentials.first << " " << account.credentials.second << '\n';
    return out;
}

std::istream& operator>>(std::istream& in
                        , Account& account)
{
    std::array<std::string, 2> retrieved_datas;
    in >> retrieved_datas[0] >> retrieved_datas[1];
    account = Account{retrieved_datas[0], retrieved_datas[1]};
    return in;
}