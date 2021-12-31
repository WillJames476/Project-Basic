#include <iostream>
#include <string>
#include "Account_menu.h"
#include "../Utilities/Transmitter.h"
#include "../loging/loger.h"

int main()
{
    std::string user{accounts_manager("users/users.txt")};
    transmit_data(user + " " + user);
    add_to_log({user, user, " login sector"});
    return 0;
}