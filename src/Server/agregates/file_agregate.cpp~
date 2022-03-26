#include <sstream>
#include <vector>
#include <application_agregates/file_agregates.h>

File_agregate::File_agregate(const Model_agregate& models)
        : account{Generic_file<Account_view>{models.account, "data/accounts.txt"}},
	  commline{Generic_file<Commline_view>{models.commline, "data/commline.txt"}},
	  todolist{Generic_file<Todolist_view>{models.todolist, "data/todolist.txt"}}
{
}

void File_agregate::save_all()
{
  account.save_file();
  commline.save_file();
  todolist.save_file();
}

void File_agregate::read_all()
{
  account.read_file();
  commline.read_file();
  todolist.read_file();
}
