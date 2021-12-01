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
        std::pair<std::string ,std::string> get_credential() const;
        std::vector<std::string> get_lines() const;
};

#endif