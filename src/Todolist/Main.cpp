#include <string>
#include <iostream>
#include <filesystem>
#include <array>
#include <sstream>

#include "Todolist_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::array<std::string, 2>datas{receive_data()};

    if(!datas[0].empty() && std::filesystem::exists("users/" + datas[0]))
    {
        task_manager(datas);
        transmit_data(datas[0] + " " + datas[1]);
    }
    
    return 0;
}
