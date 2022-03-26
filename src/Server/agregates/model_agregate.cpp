#include <memory>
#include <agregates/model_agregate.h>
#include <account/account_model.h>
#include <commline/Commline_model.h>
#include <todolist/Todolist_model.h>

Model_agregate::Model_agregate()
  : account{std::make_shared<Account_model>(Account_model{})},
    commline{std::make_shared<Commline_model>(Commline_model{})},
    todolist{std::make_shared<Todolist_model>(Todolist_model{})}
{
}
