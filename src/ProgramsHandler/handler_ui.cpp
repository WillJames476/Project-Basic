#include <iostream>
#include <stdlib.h>
#include <regex>
#include "../Utilities/io.h"
#include "../Utilities/Transmitter.h"
#include "handler_ui.h"

void handler_ui()
{
    std::string user_command{};

    while(user_command != "./exit")
    {
        user_command = get_string("enter the user command here: ", 
        string_predicates("Command"));

        if(std::regex_search(user_command, std::regex("./")))
        {
            std::system(user_command.c_str());
        }
    }
}