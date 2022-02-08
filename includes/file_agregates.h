#ifndef FILE_AGREGATES_H
#define FILE_AGREGATES_H

#include <functional>
#include <string>
#include <fstream>

#include "generic_file.h"
#include "account_model.h"

#include "model_agregate.h"

struct File_agregate
{
    Generic_file<Account_model> account;

    File_agregate(const Model_agregate& models)
        : account{Generic_file<Account_model>{models.account}}
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

        save_file(account, account_write);
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

        read_file(account, account_read);
    }   
};

#endif