/*
 * todolist v1.6
 * by: William James Landicho
 * date started: November 4 2021
 * date last updated : November 24 2021
 * 
 * version 1.0:
 *      basic task_management (deletion and addition of task),
 *      file persistence implemented
 * version 1.5:
 *      accounts system added
 * version 1.6:
 *      months date checking added, now out of date tasks will
 *      be removed from the list, bug fixed where when making new account
 *      two files are created when it is inteded to be only one
 *      added a feature where tou can only view tasks that is only on the
 *      current date
*/

/*
 * libraries used
*/
#include <string>
#include <iostream>
#include "Todolist_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::string file_of_the_user{receive_data()};
    if(!file_of_the_user.empty())task_manager("users/"+ file_of_the_user + "/" + file_of_the_user + ".csv");
    return 0;
}
