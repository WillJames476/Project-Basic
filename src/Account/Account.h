#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

class Account
{
    private:
        std::pair<std::string, std::string> credentials;
    public:
        Account();
        Account(const std::string& user_name, const std::string& user_pass);
        std::pair<std::string, std::string> get_credential()const;

        friend std::ostream& operator<<(std::ostream& out, const Account& acount);
        friend std::istream& operator>>(std::istream& in, Account& acount);
};

#endif
