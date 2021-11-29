#ifndef USER_H
#define USER_H

#include "Account.h"
#include "Communication_lines.h"

class User
{
    private:
        Account account;
        Communication_lines lines;
    public:
        User(const std::pair<std::string, std::string>& credentials);
        User(const std::pair<std::string, std::string>& credentials,
        const std::initializer_list<std::string>& fields);
        bool is_same_credential(const std::string& account_name, 
        const std::string& account_pass);
        std::pair<std::string ,std::string> get_credential() const;
        std::vector<std::string> get_lines() const;
        void add_communication_line(const std::string& user_name);
};

#endif