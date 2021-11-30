#include <iostream>
#include <sstream>
#include <algorithm>
#include "Users_list.h"
#include "Account_menu.h"
#include "../Utilities/io.h"

void search_communication_lines(std::string& account_name, Users_list& users)
{
    std::string to_search = extract_allpha_string_from_user("enter the name here: ");
    auto x = users.get_communication_line(account_name);
    auto comm_line =  std::find(x.begin(), x.end(), to_search);

    if(comm_line == x.end())return;
    account_name = x[std::distance(x.begin(),comm_line)];
}

void user_account_management(std::string& account_name,
Users_list& users)
{
    bool menu_replay{true};

    while(menu_replay)
    {
        std::ostringstream menu;
        menu << "\n===============================\n"
            << "1\tadd a communication line\n"
            << "2\tchoose what user file to acces\n"
            << "3\texit account communications chooser\n"
            << "enter your choice here: ";
        std::cout << menu.str();
        std::string menu_choice;
        std::getline(std::cin, menu_choice);

        switch(menu_choice.at(0))
        {
            case '1':
                users.add_communication_line
                (extract_allpha_string_from_user("user to comunicate with: "));
                break;
            case '2':
                users.print_communication_line(account_name);
                search_communication_lines(account_name,users);
                break;
            case '3':
                menu_replay = false;
                break;
        }
    }
}

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
                accounts.new_account
                (extract_allpha_string_from_user("user name"), 
                extract_allpha_string_from_user("password"));
                break;
            case '2':
                accounts.remove_account
                (extract_allpha_string_from_user("user name"), 
                extract_allpha_string_from_user("password"));
                break;
            case '3':
                user_file = accounts.account_login
                (extract_allpha_string_from_user("user name"), 
                extract_allpha_string_from_user("password"));
                break;
            case '4':
                menu_replay = false;
                break;
            default:
                break;
        }
    }
    accounts.save_to_file(accounts_file);
    if(!user_file.empty())user_account_management(user_file, accounts);
    return user_file;
}

