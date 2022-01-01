#include <iostream>
#include <sstream>

#include "Communication_line_menu.h"
#include "../Utilities/Transmitter.h"
#include "../loging/loger.h"

int main()
{
    std::array<std::string,2> user{receive_data()};

    if(!user[0].empty())
    {
        user[0] = communication_line_menu(user[0]);
        transmit_data(user[0] + " " + user[1]);
        add_to_log({user[0], user[1], " communication lines"});
    }

    return 0;
}