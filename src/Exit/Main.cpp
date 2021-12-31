#include <string>
#include <iostream>
#include <array>
#include <sstream>
#include <curses.h>

#include "../Utilities/Transmitter.h"
#include "../Utilities/io.h"
#include "../loging/loger.h"
#include "Exitui.h"

int main()
{
    std::array<std::string,2>datas{receive_data()};
    initscr();
    noecho();
    exit_ui(datas[0] + " " + datas[1]);
    endwin();
    
    if(!datas[0].empty())
    {
        add_to_log({datas[0], datas[1], " exit sector"});
    }

    return 0;
}
