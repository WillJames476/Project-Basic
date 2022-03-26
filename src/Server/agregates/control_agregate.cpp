#include <agregates/control_agregate.h>
#include <agregates/model_agregate.h>
#include <account/account_control.h>
#include <commline/Commline_control.h>
#include <todolist/Todolist_control.h>

Control_agregate::Control_agregate(const Model_agregate& models)
        : account{models.account},
	  commline{models.commline},
	  todolist{models.todolist}
{
}
