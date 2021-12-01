#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <map>
#include <memory>

#include "Account.h"
#include "../Utilities/File_management.h"

class Users_list : public File_management
{
    private:
        std::map<std::string, std::shared_ptr<Account>> users;
    public:
        void add_to_list(const std::initializer_list<std::string>& credentials);
        void add_to_list(const std::initializer_list<std::string>& credentials, bool is_new);
        void remove_from_list(const std::initializer_list<std::string>& crdentials);
        std::string account_login(const std::string& account_name, const std::string& account_password) const;
        bool does_account_exists(const std::string& account_name) const;
        void save_to_file(const std::string& accounts_file);
        void load_from_file(const std::string& accounts_file);
        friend void make_new_file(const std::string& account_name);
};

#endif