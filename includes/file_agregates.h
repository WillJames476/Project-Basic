#ifndef FILE_AGREGATES_H
#define FILE_AGREGATES_H

#include <functional>
#include <string>
#include <fstream>

#include "generic_file.h"

#include "../src/Account/Account_view.h"
#include "../src/Commline/Commline_view.h"
#include "../src/Todolist/Todolist_view.h"

#include "model_agregate.h"

struct File_agregate
{
	public:
    	File_agregate(const Model_agregate& models);
    	void save_all();
    	void read_all();

	private:
    	Generic_file<Account_view> account;
    	Generic_file<Commline_view> commline;
    	Generic_file<Todolist_view> todolist;
};

#endif
