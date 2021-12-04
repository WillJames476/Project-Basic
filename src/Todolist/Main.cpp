#include <string>
#include <iostream>
#include <filesystem>
#include <array>
#include <sstream>

#include "Todolist_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::string file_of_the_user{receive_data()};
    std::array<std::string, 2>datas;
    std::istringstream(file_of_the_user) >> datas[0] >> datas[1];

    if(!datas[0].empty() && 
    std::filesystem::exists("users/" + datas[0]))
    task_manager("users/"+ datas[0] + "/" + datas[0] + "_tasks.txt");
    transmit_data(datas[0] + " " + datas[1]);
    return 0;
}
