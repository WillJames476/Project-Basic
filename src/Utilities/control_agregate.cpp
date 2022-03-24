#include <server/control_agregate.h>
#include <server/model_agregate.h>

#include "../src/Account/account_control.h"
#include "../src/Commline/Commline_control.h"
#include "../src/Todolist/Todolist_control.h"

Control_agregate::Control_agregate(const Model_agregate& models)
        : account{models.account},
	  commline{models.commline},
	  todolist{models.todolist}
{
}
