#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <map>
#include <string>

class Accounts
{
    private:
        std::map<std::string, std::string> accounts;
    public:
        void new_account(const std::string& account_name, const std::string& account_password, const bool is_new);
        void make_new_file(const std::string& account_name);
        std::string account_login(const std::string& account_name, const std::string& account_password);
        void save_accounts_to_a_file(const std::string& accounts_file);
        void load_accounts_from_file(const std::string& accounts_file);
};

#endif