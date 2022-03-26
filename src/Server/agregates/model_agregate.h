#ifndef MODEL_AGREGATE_H
#define MODEL_AGREGATE_H

#include <memory>
#include <account/account_model.h>
#include <commline/Commline_model.h>
#include <todolist/Todolist_model.h>

struct Model_agregate
{
public:

  Model_agregate();
  
  std::shared_ptr<Account_model> account;
  std::shared_ptr<Commline_model> commline;
  std::shared_ptr<Todolist_model> todolist; 
};

#endif
