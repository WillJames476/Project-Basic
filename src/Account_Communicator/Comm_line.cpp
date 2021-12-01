#include <iostream>
#include "Comm_line_menu.h"
#include "../src/Utilities/io.h"

void search_communication_lines(std::string& account_name, Users_list& users)
{
    std::string to_search = get_string("enter the name here: ",string_predicates("Default"));
    auto x = users.get_communication_line(account_name);
    auto comm_line =  std::find(x.begin(), x.end(), to_search);

    if(comm_line == x.end())return;
    account_name = x[std::distance(x.begin(),comm_line)];
}

void user_account_management(std::string& account_name)
{
    Users_list users;
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
                (get_string("user to comunicate with: ", string_predicates("Default")));
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