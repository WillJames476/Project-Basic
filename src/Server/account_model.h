#ifndef ACCOUNT_MODEL_H
#define ACCOUNT_MODEL_H

#include <unordered_map>
#include <memory>
#include <string>
#include "account.h"

class Account_model
{
    public:
        void add_to_list(const Account& to_add);
        void remove_from_list(const Account& to_remove);
        Account get_item_from_list(const Account& to_remove) const;
        
    private:
        std::unordered_map<std::string, std::shared_ptr<Account>>accounts;
};

#endif