#ifndef FILE_AGREGATES_H
#define FILE_AGREGATES_H

#include <functional>
#include <string>
#include <fstream>

#include "generic_file.h"
#include "generic_file_s.h"

#include "../src/Account/Account_view.h"
#include "../src/Commline/Commline_view.h"
#include "../src/Todolist/Todolist_model.h"

#include "model_agregate.h"

struct File_agregate
{
    Generic_file_s<Account_view> account;
    Generic_file_s<Commline_view> commline;
    Generic_file<Todolist_model> todolist;

    File_agregate(const Model_agregate& models);
    void save_all();
    void read_all();
};

#endif
