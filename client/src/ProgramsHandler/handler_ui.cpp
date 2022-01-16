#include <iostream>
#include <stdlib.h>
#include <regex>
#include "../Utilities/io.h"

void handler_ui()
{
    std::string user_command{};
    
    while(user_command != "/exit")
    {
        user_command = get_string("> ", 
        REGEX_PREDICATES::COMMAND);

        std::string full_command{"bin"+user_command};
        std::system(full_command.c_str());
    }
}