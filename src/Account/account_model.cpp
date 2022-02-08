#include "account_model.h"

bool Account_model::add_to_list(const std::string& username
                                , const std::string password)
{
    if(accounts.find(username) == std::end(accounts))
    {
        accounts.emplace(std::make_pair(username, password));
        
        return true;
    }

    return false;
}

bool Account_model::remove_from_list(const std::string& username
                                    , const std::string password)
{
    const auto extracted_account {accounts.find(username)};

    if(extracted_account != std::end(accounts))
    {
        bool is_match{password == extracted_account->second};

        if(is_match)
        {
            accounts.erase(username);
            
            return true;
        }
    }

    return false;
}   

bool Account_model::get_item_from_list(const std::string& username
                                        , const std::string password) const
{
    const auto extracted_account {accounts.find(username)};

    if(extracted_account != std::end(accounts))
    {
        bool is_match{password == extracted_account->second};

        if(is_match)
        {
            return true;
        }
    }
    
    return false;
}


std::unordered_map<std::string, std::string>Account_model::get_accounts() const
{
    return accounts;
}