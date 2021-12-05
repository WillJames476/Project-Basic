#include <iostream>
#include <sstream>

#include "Communication_line_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::string user{receive_data()},acesed_user{};
    
    if(!user.empty())
    {
        std::istringstream(user) >> acesed_user;
        transmit_data(communication_line_menu(acesed_user));
    }
    return 0;
}