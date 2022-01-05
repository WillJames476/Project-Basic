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
        REGEX_PREDICATES::COMMAND);

        std::system(user_command.c_str());
    }
}