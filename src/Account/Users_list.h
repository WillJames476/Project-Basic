#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <map>
#include <memory>
#include <iostream>

#include "Account.h"
#include "../Utilities/List_management.h"

class Users_list : public List_management
{
    private:
        std::map<std::string, std::shared_ptr<Account>> users;
    public:
        void add_to_list(const std::initializer_list<std::string>& credentials);
        void remove_from_list(const std::initializer_list<std::string>& crdentials);
        std::string account_login(const std::string& account_name, const std::string& account_password) const;
        
        friend void make_new_file(const std::string& account_name);
        friend std::ostream& operator<<(std::ostream& out, const Users_list& user);
        friend std::istream& operator>>(std::istream& in, Users_list& user);  
};

#endif