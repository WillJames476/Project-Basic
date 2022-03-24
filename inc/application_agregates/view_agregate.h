#ifndef VIEW_AGREGATE_H
#define VIEW_AGREGATE_H

#include <memory>

#include "model_agregate.h"

#include "../src/Account/Account_view.h"
#include "../src/Commline/Commline_view.h"
#include "../src/Todolist/Todolist_view.h"

struct View_agregate
{
	Account_view account;
	Commline_view commline;
	Todolist_view todolist;

	View_agregate(const Model_agregate& model)
		: account{Account_view{model.account}}
		, commline{Commline_view{model.commline}}
		, todolist{Todolist_view{model.todolist}}
	{
	}
};

#endif
