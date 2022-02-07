#ifndef ACCOUNT_MODEL_H
#define ACCOUNT_MODEL_H

#include <string>
#include <vector>

class Account_model
{
    public:
        Account_model() = default;
        Account_model(const std::string& account_name, const std::string& account_password);

        std::string get_account_password() const;
        std::string get_account_username() const;
        int get_field_count() const;

        void set_account_password(const std::string& new_value);
        void set_account_username(const std::string& new_value);

        friend bool operator== (const Account_model& first, const Account_model& second);
    private:
        std::string account_username_string;
        std::string account_password_string;

        const static int field_count = 2;
};

#endif
