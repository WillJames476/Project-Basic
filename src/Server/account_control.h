#ifndef ACCOUNT_CONTROL_H
#define ACCOUNT_CONTROL_H

#include <unordered_map>
#include <memory>
#include <string>
#include "account_model.h"

class Account_control
{
    public:
        void add_to_list(const Account_model& to_add);
        void remove_from_list(const Account_model& to_remove);
        Account_model get_item_from_list(const Account_model& to_remove) const;
        
    private:
        std::unordered_map<std::string, std::shared_ptr<Account_model>>accounts;
};

#endif