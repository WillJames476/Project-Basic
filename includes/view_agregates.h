#ifndef VIEW_AGREGATES_H
#define VIEW_AGREGATES_H

#include "model_agregates.h"
#include "../src/Todolist_view.h"
#include "../src/Account_view.h"
#include "../src/Commline_view.h"

struct View_agregates
{
    Account_view account;
    Commline_view commline;
    Todolist_view todolist;

    view_agregates(const Model_agregate& model)
        : account{model.account}
        , commline{model.commline}
        , todolist{model.todolist}
    {
    }
};

#endif