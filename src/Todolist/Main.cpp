#include <string>
#include <iostream>
#include <filesystem>
#include <array>
#include <sstream>

#include "Todolist_menu.h"
#include "../Utilities/Transmitter.h"
#include "../loging/loger.h"

int main()
{
    std::array<std::string, 2>datas{receive_data()};

    if(!datas[0].empty() && std::filesystem::exists("users/" + datas[0]))
    {
        task_manager(datas);
        transmit_data(datas[0] + " " + datas[1]);
        add_to_log({datas[0], datas[1], "task sector"});
    }
    
    return 0;
}
