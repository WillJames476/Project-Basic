#ifndef FILE_AGREGATES_H
#define FILE_AGREGATES_H

#include <functional>
#include <string>
#include <fstream>

#include "generic_file.h"
#include "../src/Account/account_model.h"
#include "../src/Commline/Commline_model.h"

#include "model_agregate.h"

struct File_agregate
{
    Generic_file<Account_model> account;
    Generic_file<Commline_model> commline;

    File_agregate(const Model_agregate& models);
    void save_all();
    void read_all();
};

#endif