#include "account_control.h"
#include <algorithm>
#include <array>
#include <string>

Account_control::Account_control(const std::shared_ptr<Account_model>& account_model)
    : model{account_model}
{

}

std::string Account_control::add_to_list(const std::initializer_list<std::string>& fields) const
{
    std::string string_to_return{"unsuccessfull operation"};

    if(fields.size() == 2)
    {   
        auto datas = std::data(fields);
        
        if(model->add_to_list(*datas, *(datas + 1)))
        {
            string_to_return = "succesfull operation";
        }
    }
 
    return string_to_return;
}

std::string Account_control::remove_from_list(const std::initializer_list<std::string>& fields) const
{
    std::string string_to_return{"unsuccessfull operation"};

    if(fields.size() == 2)
    {
        auto datas = std::data(fields);

        if(model->remove_from_list(*datas, *(datas + 1)))
        {
            string_to_return = "sucessfull operation";
        }
    }

    return string_to_return;
}

std::string Account_control::get_from_list(const std::initializer_list<std::string>& fields) const
{
    std::string string_to_return{"unsuccessfull operation"};

    if(fields.size() == 2)
    {
        auto datas = std::data(fields);

        if(model->get_item_from_list(*datas, *(datas + 1)))
        {
            string_to_return = *datas + " " + *(datas + 1);
        }
    }

    return string_to_return;
}

bool Account_control::is_user_existing(const std::string& username) const
{
    return model->get_is_account_existing(username);
}
