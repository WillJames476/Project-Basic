#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
    private:
        std::pair<std::string, std::string> credentials;
    public:
        Account(const std::string& user_name, const std::string& user_pass);
        std::pair<std::string, std::string> get_credential();
};

#endif
