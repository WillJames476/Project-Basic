#ifndef VIEW_AGREGATE_H
#define VIEW_AGREGATE_H

#include <memory>
#include <agregates/model_agregate.h>
#include <account/Account_view.h>
#include <commline/Commline_view.h>
#include <todolist/Todolist_view.h>

struct View_agregate
{
  Account_view account;
  Commline_view commline;
  Todolist_view todolist;

  View_agregate(const Model_agregate& model);
};

#endif
