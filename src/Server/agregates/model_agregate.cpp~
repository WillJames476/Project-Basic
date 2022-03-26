#include <memory>
#include <application_agregates/model_agregate.h>

#include "../src/Account/account_model.h"
#include "../src/Commline/Commline_model.h"
#include "../src/Todolist/Todolist_model.h"

Model_agregate::Model_agregate()
  : account{std::make_shared<Account_model>(Account_model{})},
    commline{std::make_shared<Commline_model>(Commline_model{})},
    todolist{std::make_shared<Todolist_model>(Todolist_model{})}
{
}
