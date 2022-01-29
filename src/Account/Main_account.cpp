#include <iostream>
#include <string>
#include "Account_menu.h"
#include "../includes/Transmitter.h"
#include "../includes/loger.h"

int main(int argc
        , char** argv)
{
    std::string user{account_manager_cli(argc, argv,"users/users.txt")};
    transmit_data(user + " " + user);
    add_to_log({user, user, " login sector"});
    return 0;
}