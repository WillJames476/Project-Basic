#include "Commline_model.h"

void Commline_model::add_to_list(const std::string& account_name)
{
    commlines.emplace(account_name, std::make_shared<Permission_table>(Permission_table{}));
}

void Commline_model::remove_from_list(const std::string& account_name)
{
    commlines.erase(account_name);
}

bool Commline_model::is_permitted(const std::string& accessor, const std::string& accessed)
{
    return commlines.find(accessor)->second->is_permitted(accessed);
}

std::unordered_map<std::string, std::shared_ptr<Permission_table>>  
    Commline_model::get_commlines() const
{
    return commlines;
}