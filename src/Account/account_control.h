#ifndef ACCOUNT_CONTROL_H
#define ACCOUNT_CONTROL_H

#include <memory>
#include <string>
#include "account_model.h"

class Account_control
{
    public:
        Account_control(const std::shared_ptr<Account_model>& model);

        std::string add_to_list(const std::initializer_list<std::string>& fields) const;

        std::string remove_from_list(const std::initializer_list<std::string>& fields) const;

        std::string get_from_list(const std::initializer_list<std::string>& fields) const;

        bool is_user_existing(const std::string& username) const;

    private:
        std::shared_ptr<Account_model>model;
};

#endif