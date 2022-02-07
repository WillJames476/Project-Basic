#include "account_model.h"

void Account_model::add_to_list(const Account& to_add)
{
    accounts.emplace(std::make_pair(to_add.get_account_username()
        ,std::make_shared<Account>(to_add)));
}

void Account_model::remove_from_list(const Account& to_remove)
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

Account Account_model::get_item_from_list(const Account& to_find) const
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
    
    return Account{};
}
