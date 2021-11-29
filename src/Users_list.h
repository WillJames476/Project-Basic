#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <map>
#include <memory>
#include "User.h"

class Users_list
{
    private:
        std::map<std::string, std::shared_ptr<User>> users;
    public:
        friend void make_new_file(const std::string& account_name);
        void new_account(const std::string& account_name,
        const std::string& account_password, const bool is_new);
        void remove_account(const std::string& account_name,
        const std::string& account_password);
        std::vector<std::string> get_lines() const;
        std::vector<std::string> account_login(const std::string& account_name, 
        const std::string& account_password) const;
        void save_accounts_to_a_file(const std::string& accounts_file);
        void load_accounts_from_file(const std::string& accounts_file);
};

#endif