#include <agregates/view_agregate.h>

View_agregate::View_agregate(const Model_agregate& model)
  : account{Account_view{model.account}},
    commline{Commline_view{model.commline}},
    todolist{Todolist_view{model.todolist}}
{
}
