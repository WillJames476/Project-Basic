#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

#include "Users_list.h"
#include "Account_menu.h"
#include "../Utilities/io.h"

void load_from_file(const std::string& accounts_file, Users_list& users)
{
    try
    {
        std::fstream file_to_read(accounts_file, std::ios_base::in);
        file_to_read >> users;
        file_to_read.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void save_to_file(const std::string& accounts_file, const Users_list& users)
{
    try
    {
        std::fstream file_archiver(accounts_file, std::ios_base::out);
        file_archiver << users;
        file_archiver.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void accounts_manager_control_flow(std::string& user_file, 
char menu_choice,bool& menu_replay, Users_list &accounts)
{
    switch (menu_choice)
    {
        case '1':
            accounts.add_to_list
            ({get_string("enter the user name here: ", string_predicates("Default")), 
            get_string("enter the password here:" , string_predicates("Default")),"1"});
            break;
        case '2':
            accounts.remove_from_list
            (Account{get_string("enter the user name here: ", string_predicates("Default")), 
            get_string("enter the password here: ", string_predicates("Default"))});
            break;
        case '3':
            user_file = accounts.get_item_from_list
            (Account{get_string("enter the user name here: ", string_predicates("Default")), 
            get_string("enter the password here: ", string_predicates("Default"))})
            .get_credential().first;
            break;
        case '4':
            menu_replay = false;
            break;
    }
}

char accounts_manager_menu()
{
    std::ostringstream menu;
    menu  << "\n=================================\n"
          << "1\tadd a user\n"
          << "2\tremove a user\n"
          << "3\tuser login\n"
          << "4\texit login sector\n"
          << "enter your choice here: ";
    return get_integral<char>(menu.str(),'0','5');
}

std::string accounts_manager(const std::string& accounts_file)
{
    Users_list accounts;
    std::string menu_choice, user_file;
    bool menu_replay{true};

    load_from_file(accounts_file, accounts);

    while(menu_replay)
    {
        accounts_manager_control_flow(user_file,accounts_manager_menu(),
        menu_replay, accounts);
    }

    save_to_file(accounts_file, accounts);
    return user_file;
}
