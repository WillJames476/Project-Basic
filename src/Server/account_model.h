#ifndef ACCOUNT_MODEL_H
#define ACCOUNT_MODEL_H

#include <unordered_map>
#include <memory>
#include <string>

class Account_model
{
    public:
        
        bool add_to_list(const std::string& username
                        , const std::string password);

        bool remove_from_list(const std::string& username
                            , const std::string password);

        bool get_item_from_list(const std::string& username
                            , const std::string password) const;
        
    private:
        std::unordered_map<std::string, std::string>accounts;
};

#endif