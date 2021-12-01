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
            std::cout << comms;
            comms.remove_from_list
            ({get_string("enter the name of user here: ",
            string_predicates("Default"))});
            break;
        case '3':
            std::cout << comms;
            break;
        case '4':
            {
                std::cout << comms;
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

void load_from_file(const std::string& file_name, Communication_lines&lines)
{
    lines.add_to_list({file_name});

    try
    {   
        std::ifstream file_to_load(file_name);
        file_to_load >> lines;
        file_to_load.close();
    }
    catch(std::exception &s)
    {
        std::cerr << "File not found / input corrupted\n";
    }    
}

void save_to_file(const std::string& file_name, const Communication_lines& lines)
{
    try
    {   
        std::ofstream file_to_load(file_name);
        file_to_load << lines;
        file_to_load.close();
    }
    catch(std::exception &s)
    {
        std::cerr << "File not found / input corrupted\n";
    }
}

std::string communication_line_menu(std::string& file_name)
{
    Communication_lines comms;
    bool menu_replay{true};
    const std::string permanent_file_name{"users/" + file_name + "/" + file_name + "_comms.csv"};

    load_from_file(permanent_file_name,comms);
    while(menu_replay)
    {
        communication_line_control_flow
        (comms,get_menu_choice(),file_name, menu_replay);
    }
    save_to_file(permanent_file_name,comms);
    return file_name;
}