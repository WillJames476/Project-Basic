#ifndef CONTROL_AGREGATE_H
#define CONTROL_AGREGATE_H

#include "../src/Account/account_control.h"
#include "../src/Commline/Commline_control.h"

#include "model_agregate.h"

struct Control_agregate
{
    Account_control account;
    Commline_control commline;

    Control_agregate(const Model_agregate& models)
        : account{models.account}, commline{models.commline}
    {
    }   
};

#endif
