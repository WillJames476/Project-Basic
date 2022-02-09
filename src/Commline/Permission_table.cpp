#include "Permission_table.h"

void Permission_table::add_to_table(const std::string& name, const bool permission)
{
    bool is_existing{permission_table.find(name) != std::end(permission_table)};

    if(!is_existing)
    {
        permission_table.emplace(std::make_pair(name, permission));
    }
}

std::pair<std::string, bool> Permission_table::get_from_table(const std::string& name) const
{
    std::pair<std::string, bool> to_return{std::string{}, false};

    auto iterator{permission_table.find(name)};
    bool is_existing{iterator != std::end(permission_table)};
 
    if(is_existing)
    {
        to_return = *iterator;
    }

    return to_return;
}

void Permission_table::remove_from_table(const std::string& name)
{
    permission_table.erase(name);
}

std::unordered_map<std::string, bool> Permission_table::get_table() const
{
    return permission_table;
}

bool Permission_table::is_permitted(const std::string& name) const
{
    auto name_location{permission_table.find(name)};
    bool is_existing{name_location != std::end(permission_table)};

    return is_existing ? name_location->second : false;
}