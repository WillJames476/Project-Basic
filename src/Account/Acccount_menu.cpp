#include <iostream>
#include <sstream>
#include <algorithm>
#include "Users_list.h"
#include "Account_menu.h"
#include "../Utilities/io.h"

std::string accounts_manager(const std::string& accounts_file)
{
    Users_list accounts;
    std::string menu_choice, user_file;
    bool menu_replay = true;

    accounts.load_from_file(accounts_file);

    while(menu_replay)
    {
        std::cout << "\n=================================\n"
                  << "1\tadd a user\n"
                  << "2\tremove a user\n"
                  << "3\tuser login\n"
                  << "4\texit program\n"
                  << "enter your choice here: ";
        std::getline(std::cin, menu_choice);

        switch (menu_choice.at(0))
        {
            case '1':
                accounts.add_to_list
                ({get_string("enter the user name here: ", string_predicates("Default")), 
                get_string("enter the password here:", string_predicates("Default"))});
                break;
            case '2':
                accounts.remove_from_list
                ({get_string("enter the user name here: ", string_predicates("Default")), 
                get_string("enter the password here: ", string_predicates("Default"))});
                break;
            case '3':
                user_file = accounts.account_login
                (get_string("enter the user name here: ", string_predicates("Default")), 
                get_string("enter the password here: ", string_predicates("Default")));
                break;
            case '4':
                menu_replay = false;
                break;
            default:
                break;
        }
    }
    accounts.save_to_file(accounts_file);
    return user_file;
}

