#include <string>
#include <iostream>
#include <filesystem>

#include "Todolist_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::string file_of_the_user{receive_data()};
    if(!file_of_the_user.empty() && std::filesystem::exists("users/" +file_of_the_user))
    task_manager("users/"+ file_of_the_user + "/" + file_of_the_user + ".csv");
    return 0;
}
