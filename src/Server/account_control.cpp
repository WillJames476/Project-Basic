#include "account_control.h"

void Account_control::add_to_list(const Account_model& to_add)
{
    accounts.emplace(std::make_pair(to_add.get_account_username()
        ,std::make_shared<Account_model>(to_add)));
}

void Account_control::remove_from_list(const Account_model& to_remove)
{
    const auto username_string   {to_remove.get_account_username()};
    const auto extracted_account {accounts.find(username_string)};

    if(extracted_account != std::end(accounts))
    {
        bool is_match{to_remove == *extracted_account->second};

        if(is_match)
        {
            accounts.erase(username_string);
        }
    }
}   

Account_model Account_control::get_item_from_list(const Account_model& to_find) const
{
    const auto username_string   {to_find.get_account_username()};
    const auto extracted_account {accounts.find(username_string)};

    if(extracted_account != std::end(accounts))
    {
        bool is_match{to_find == *extracted_account->second};

        if(is_match)
        {
            return to_find;
        }
    }
    
    return Account_model{};
}
