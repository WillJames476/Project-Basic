#include <sstream>
#include "Communication_line.h"
#include "Communication_line_menu.h"
#include "../Utilities/io.h"

std::string communication_line_menu(const std::string& file_name)
{
    bool menu_replay{true};

    while(menu_replay)
    {
        std::ostringstream menu;
        menu << "\n======================================\n"
             << "1\tadd a communication line\n"
             << "2\tremove a communication line\n"
             << "3\tview all communication line\n"
             << "4\tacces a communication line\n"
             << "5\texit communication sector\n"
             << "enter you choice here: ";
        char menu_choice = get_integral<char>(menu.str(),'0','6');

        switch(menu_choice)
        {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                menu_replay = false;
                break;
        }
    }

    return file_name;
}