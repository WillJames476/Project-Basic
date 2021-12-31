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
        transmit_data(communication_line_menu(user[0]));
    }

    return 0;
}