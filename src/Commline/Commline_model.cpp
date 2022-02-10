#include "Commline_model.h"

void Commline_model::add_to_list(const std::string& account_name)
{
    commlines.emplace(account_name, std::make_shared<Permission_table>(Permission_table{}));
}

void Commline_model::add_to_list_acess(const std::string& account_name
                                    , const std::string& account_to_access
                                    , const bool permission)
{
    auto table_ptr{commlines.find(account_name)};

    if(table_ptr != std::end(commlines))
    {
        table_ptr->second->add_to_table(account_to_access, permission);
    }
}

void Commline_model::remove_from_list(const std::string& account_name)
{
    commlines.erase(account_name);
}

void Commline_model::remove_from_list_acess(const std::string& account_name
                                    , const std::string& account_to_access)
{
    auto table_ptr{commlines.find(account_name)};

    if(table_ptr != std::end(commlines))
    {
        table_ptr->second->remove_from_table(account_to_access);
    }
}

bool Commline_model::is_permitted(const std::string& accessor
                                , const std::string& accessed)
{
    return commlines.find(accessor)->second->is_permitted(accessed);
}

bool Commline_model::modify_permission(const std::string& accessor
                            , const std::string& target
                            , const bool new_permission)const
{
    auto table_ptr{commlines.find(accessor)};

    if(table_ptr != std::end(commlines))
    {
        table_ptr->second->modify_permission(target, new_permission);
        return true;
    }

    return false;
}

std::unordered_map<std::string, std::shared_ptr<Permission_table>>  
    Commline_model::get_commlines() const
{
    return commlines;
}