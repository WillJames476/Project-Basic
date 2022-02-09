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
        
        void remove_from_list(const std::string& name);

        bool is_permitted(const std::string& acessor
                        , const std::string& accessed);
        
    private:
        std::unordered_map<std::string, std::shared_ptr<Permission_table>> commlines;
};  

#endif