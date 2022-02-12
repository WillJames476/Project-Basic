#ifndef MODEL_AGREGATE_H
#define MODEL_AGREGATE_H

#include <memory>

#include "../src/Account/account_model.h"
#include "../src/Commline/Commline_model.h"
#include "../src/Todolist/Todolist_model.h"

struct Model_agregate
{
    std::shared_ptr<Account_model> account;
    std::shared_ptr<Commline_model> commline;
    std::shared_ptr<Todolist_model> todolist;
 
    Model_agregate()
        : account{std::make_shared<Account_model>(Account_model{})}
        , commline{std::make_shared<Commline_model>(Commline_model{})}
        , todolist{std::make_shared<Todolist_model>(Todolist_model{})}
    {
    }
};

#endif
