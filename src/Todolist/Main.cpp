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
