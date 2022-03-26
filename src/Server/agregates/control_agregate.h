#ifndef CONTROL_AGREGATE_H
#define CONTROL_AGREGATE_H

#include <account/account_control.h>
#include <commline/Commline_control.h>
#include <todolist/Todolist_control.h>
#include <agregates/model_agregate.h>

struct Control_agregate
{
public:

  Control_agregate(const Model_agregate& models);   
  
  Account_control account;
  Commline_control commline;
  Todolist_control todolist;
  
};

#endif
