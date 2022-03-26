#ifndef FILE_AGREGATES_H
#define FILE_AGREGATES_H

#include <functional>
#include <string>
#include <fstream>
#include <agregates/model_agregate.h>
#include <agregates/generic_file.h>
#include <account/Account_view.h>
#include <commline/Commline_view.h>
#include <todolist/Todolist_view.h>


struct File_agregate
{
public:

  File_agregate(const Model_agregate& models);

  void
  save_all();

  void
  read_all();

private:

  Generic_file<Account_view> account;

  Generic_file<Commline_view> commline;

  Generic_file<Todolist_view> todolist;
  
};

#endif
