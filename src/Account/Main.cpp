#include <iostream>
#include <string>
#include "Account_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::string user{accounts_manager("users/users.txt")};
    transmit_data(user + " " + user);
    return 0;
}