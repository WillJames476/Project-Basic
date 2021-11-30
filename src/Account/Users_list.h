#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <map>
#include <memory>
#include "User.h"
#include "../Utilities/File_management.h"

class Users_list : public File_management
{
    private:
        std::map<std::string, std::shared_ptr<User>> users;
    public:
        friend void make_new_file(const std::string& account_name);
        void new_account(const std::string& account_name,
        const std::string& account_password);
        void new_account(const std::string& account_name, 
        const std::string &account_password,
        const std::vector<std::string>& lines);
        void remove_account(const std::string& account_name,
        const std::string& account_password);
        std::string account_login(const std::string& account_name, 
        const std::string& account_password) const;
        std::vector<std::string> get_communication_line
        (const std::string& user_name) const;
        void add_communication_line(const std::string& user_name);
        void print_communication_line(const std::string& user_name);
        void save_to_file(const std::string& accounts_file);
        void load_from_file(const std::string& accounts_file);
};

#endif