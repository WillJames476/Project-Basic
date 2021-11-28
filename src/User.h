#ifndef USER_H
#define USER_H

#include "Account.h"

class User
{
    private:
        Account account;
    public:
        User(const std::string& user_name, const std::string& user_pass);
        bool is_same_credential(const std::string& account_name, 
        const std::string& account_pass);
        std::pair<std::string ,std::string> get_credential();
};

#endif