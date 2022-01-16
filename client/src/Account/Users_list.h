#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>

#include "Account.h"
#include "../includes/List_crtp.h"

class Users_list : public List_crtp<Users_list, Account>
{
    public:
        void add_item(const std::initializer_list<std::string>&datas);
        void remove_item(const Account& to_remove);
        Account get_item(const Account& to_get);

        friend void make_new_file(const std::string& account_name);
        friend std::ostream& operator<<(std::ostream& out, const Users_list& user);
        friend std::istream& operator>>(std::istream& in, Users_list& user);

	private:
		std::unordered_map<std::string, std::shared_ptr<Account>> users;
};

#endif
