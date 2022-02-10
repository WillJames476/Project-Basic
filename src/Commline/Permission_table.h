#ifndef PERMISSION_TABLE_H
#define PERMISSION_TABLE_H

#include <string>
#include <unordered_map>

class Permission_table
{
    public:
        Permission_table() = default;
        
        void add_to_table(const std::string& name
                        , const bool permission);

        std::pair<std::string, bool> get_from_table(const std::string& name) const;

        void remove_from_table(const std::string& name);

        std::unordered_map<std::string, bool>get_table() const;

        bool is_permitted(const std::string& name) const;

        bool modify_permission(const std::string& name, const bool new_value);

    private:
        std::unordered_map<std::string, bool> permission_table;
};

#endif