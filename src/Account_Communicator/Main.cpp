#include <iostream>

#include "Communication_line_menu.h"

int main()
{
    std::string user{"ingrid"};
    //transmit_data(user);
    std::cout << communication_line_menu(user) << '\n';
    return 0;
}