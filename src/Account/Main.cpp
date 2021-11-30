#include <iostream>
#include <string>
#include "Account_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::string user{accounts_manager("users/users.csv")};
    transmit_data(user);
    return 0;
}