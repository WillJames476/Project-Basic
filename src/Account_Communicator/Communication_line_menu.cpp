#include <sstream>
#include <fstream>
#include "Communication_line.h"
#include "Communication_line_menu.h"
#include "../Utilities/io.h"

char get_menu_choice()
{
    std::ostringstream menu;
    menu << "\n======================================\n"
         << "1\tadd a communication line\n"
         << "2\tremove a communication line\n"
         << "3\tview all communication line\n"
         << "4\talter other user's permission on your files\n"
         << "5\tacces a communication line and exit the\n"
         << " \tcommunication line sector\n"
         << "enter you choice here: ";
    
    return get_integral<char>(menu.str(),'0','6');
}

std::string communication_line_control_flow(Communication_lines& comms, char menu_choice,
std::string& file_name, bool& menu_replay, const std::string& permanent_user)
{
    switch(menu_choice)
    {
        case '1':
            comms.add_to_list
            (get_string("enter the name of user here: ",
            string_predicates("Default")), 0);
            break;
        case '2':
            std::cout << comms;
            comms.remove_from_list
            (get_string("enter the name of user here: ",
            string_predicates("Default")));
            break;
        case '3':
            std::cout << comms;
            break;
        case '4':
            comms.alter_permission
            (permanent_user,get_string("enter the name of user here: ",
            string_predicates("Default")));
            break;
        case '5':
            {
                std::cout << comms;
                file_name = comms.get_item_from_list
                (get_string("enter the name of user here: ",
                string_predicates("Default")));
                menu_replay = false;
            }  
            break;
    }
    return file_name;
}

std::string communication_line_menu(std::string& file_name)
{
    Communication_lines comms{};
    bool menu_replay{true};
    const std::string permanent_file_name{"users/" + file_name + "/" + file_name + "_comms.txt"},
    permanent_user{file_name};
    
    comms.add_to_list(permanent_user, 1);
    load_from_file(permanent_file_name, comms);
    while(menu_replay)
    {
        communication_line_control_flow
        (comms,get_menu_choice(),file_name, menu_replay, permanent_user);
    }
    save_to_file(permanent_file_name,comms);
    file_name += " " + permanent_user;
    return file_name;
}