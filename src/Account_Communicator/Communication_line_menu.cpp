#include <sstream>
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
         << "4\tacces a communication line\n"
         << "5\texit communication sector\n"
         << "enter you choice here: ";
    
    return get_integral<char>(menu.str(),'0','6');
}

std::string communication_line_control_flow(Communication_lines& comms, char menu_choice,
std::string& file_name, bool& menu_replay)
{
    switch(menu_choice)
    {
        case '1':
            comms.add_to_list
            ({{get_string("enter the name of user here: ",
            string_predicates("Default"))}});
            break;
        case '2':
            comms.print_list();
            comms.remove_from_list
            ({get_string("enter the name of user here: ",
            string_predicates("Default"))});
            break;
        case '3':
            comms.print_list();
            break;
        case '4':
            {
                comms.print_list();
                auto new_val{comms.get_item_from_list
                ({get_string("enter the name of user here: ",
                string_predicates("Default"))})};
                if(new_val != std::string()) file_name = new_val;
            }  
            break;
        case '5':
            menu_replay = false;
            break;
    }
    return file_name;
}

std::string communication_line_menu(std::string& file_name)
{
    Communication_lines comms;
    bool menu_replay{true};

    while(menu_replay)
    {
        communication_line_control_flow
        (comms,get_menu_choice(),file_name, menu_replay);
    }

    return file_name;
}