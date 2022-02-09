#include <array>
#include <string>
#include <iostream>
#include <memory>

#include "../Commline/Commline_model.h"
#include "../Commline/Commline_control.h"

int main()
{
    auto ptr{std::make_shared<Commline_model>(Commline_model{})};
    auto control{Commline_control{ptr}};

    std::array<std::string, 5>names{"johny", "sylvester", "mkaers", "bazaar", "jane"};

    for(const auto& x : names)
    {
        control.add_to_list({x});
    }

    auto table{ptr->get_commlines()};

    for(const auto& x : table)
    {
        const auto& y{x.second->get_from_table("johny")};
        
        std::cout << x.first << " "
                << y.first << " " 
                << y.second << '\n';
    }

    return 0;
}