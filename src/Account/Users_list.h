#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <map>
#include <memory>

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
        void save_to_file(const std::string& accounts_file);
        void load_from_file(const std::string& accounts_file);
        friend void make_new_file(const std::string& account_name);
};

#endif