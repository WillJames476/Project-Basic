#include "Commline_model.h"

bool Commline_model::add_to_list(const std::string& account_name)
{
  if(commlines.find(account_name) == std::end(commlines))
    {
      commlines.emplace(account_name,
			std::make_shared<Permission_table>(Permission_table{}));

      return true;
    }

  return false;
}

bool Commline_model::add_to_list_acess(const std::string& account_name,
				       const std::string& account_to_access,
				       const bool permission)
{
  auto table_ptr{commlines.find(account_name)};

  if(table_ptr != std::end(commlines))
    {
      table_ptr->second->add_to_table(account_to_access, permission);
      return true;
    }

  return false;
}

bool Commline_model::remove_from_list(const std::string& account_name)
{
  if(commlines.find(account_name) != std::end(commlines))
    {
      commlines.erase(account_name);
      return true;
    }

  return false;
}

bool Commline_model::remove_from_list_acess(const std::string& account_name,
					    const std::string& account_to_access)
{
  auto table_ptr{commlines.find(account_name)};

  if(table_ptr != std::end(commlines))
    {
      table_ptr->second->remove_from_table(account_to_access);
      return true;
    }

  return false;
}

bool Commline_model::is_permitted(const std::string& accessor,
				  const std::string& accessed)
{
  return commlines.find(accessor)->second->is_permitted(accessed);
}

bool Commline_model::modify_permission(const std::string& accessor,
				       const std::string& target,
				       const bool new_permission)const
{
  auto table_ptr{commlines.find(accessor)};

  if(table_ptr != std::end(commlines))
    {
      table_ptr->second->modify_permission(target, new_permission);
      return true;
    }

  return false;
}

std::shared_ptr<Permission_table> Commline_model::get_permission_table(const std::string& account) const
{
  return commlines.find(account)->second;
}

std::unordered_map<std::string, std::shared_ptr<Permission_table>>  
    Commline_model::get_commlines() const
{
  return commlines;
}
