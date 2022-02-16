#ifndef COMMLINE_MODEL_H
#define COMMLINE_MODEL_H

#include <string>
#include <unordered_map>
#include <memory>

#include "Permission_table.h"

class Commline_model
{
    public:
        Commline_model() = default;

        void add_to_list(const std::string& name);

        void add_to_list_acess(const std::string& name
                                , const std::string& to_acess
                                , const bool permission);

        void remove_from_list(const std::string& name);

        void remove_from_list_acess(const std::string& name
                                    , const std::string& to_acess);

        bool is_permitted(const std::string& acessor
                        , const std::string& accessed);

        bool modify_permission(const std::string& acessor
                            , const std::string& target
                            , const bool new_permission)const;

		std::shared_ptr<Permission_table> get_permission_table(const std::string& name) const;

        std::unordered_map<std::string, std::shared_ptr<Permission_table>>
            get_commlines() const;

    private:
        std::unordered_map<std::string, std::shared_ptr<Permission_table>> commlines;
};

#endif
