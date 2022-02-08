#ifndef MODEL_AGREGATE_H
#define MODEL_AGREGATE_H

#include <memory>

#include "../src/Account/account_model.h"

struct Model_agregate
{
    std::shared_ptr<Account_model>account;

    Model_agregate()
    {
        account = std::make_shared<Account_model>(Account_model{});
    }
};

#endif
