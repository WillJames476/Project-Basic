#ifndef FILE_AGREGATES_H
#define FILE_AGREGATES_H

#include <functional>
#include <string>
#include <fstream>

#include "generic_file.h"
#include "../src/Account/account_model.h"
#include "../src/Commline/Commline_model.h"

#include "model_agregate.h"

struct File_agregate
{
    Generic_file<Account_model> account;
    Generic_file<Commline_model> commline;

    File_agregate(const Model_agregate& models)
        : account{Generic_file<Account_model>{models.account, "accounts.txt"}}
        , commline{Generic_file<Commline_model>{models.commline, "commline.txt"}}
    {

    }

    void save_all()
    {
        auto account_write{[](auto& x)
            {
                std::string to_return{};

                for(const auto& y : x->get_accounts())
                {
                    to_return += y.first + " " + y.second + "\n"; 
                }

                return to_return;
            }};

        auto commline_write{[](auto& x)
            {
                std::string to_return{};

                for(const auto& y : x->get_commlines())
                {
                    to_return += y.first + '\n';
                }

                std::cout << "to return" << to_return;
                return to_return;
            }};

        save_file(account, account_write);
        save_file(commline, commline_write);
    }

    void read_all()
    {
        auto account_read{[](auto& x, auto& y)
            {
                std::array<std::string, 2>fields;
                
                while(x >> fields[0] >> fields[1])
                {
                    y->add_to_list(fields[0], fields[1]);
                }
            }};

        auto commline_read{[](auto& x, auto& y)
            {
                std::string user_name{};

                while(x >> user_name)
                {
                    y->add_to_list(user_name);
                }
            }};

        read_file(account, account_read);
        read_file(commline, commline_read);
    }   
};

#endif