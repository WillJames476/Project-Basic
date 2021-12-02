#include <iostream>

#include "Communication_line_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::string user{receive_data()};
    if(!user.empty()){transmit_data(communication_line_menu(user));}
    return 0;
}