#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>

#include "Account.h"

class Users_list
{
    public:
        void add_to_list(const std::string& user_name, const std::string& user_pass, bool is_new); 
        void remove_from_list(const std::string& user_name, const std::string& user_pass);
        std::string account_login(const std::string& account_name, const std::string& account_password) const;

        friend void make_new_file(const std::string& account_name);
        friend std::ostream& operator<<(std::ostream& out, const Users_list& user);
        friend std::istream& operator>>(std::istream& in, Users_list& user);

	private:
		std::unordered_map<std::string, std::shared_ptr<Account>> users;
};

#endif
