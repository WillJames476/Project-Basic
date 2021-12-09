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
    std::string received_data{receive_data()};
    std::array<std::string,2>datas;

    std::istringstream(received_data) >> datas[0] >> datas[1];
    initscr();
    noecho();
    exit_ui(datas[0] + " " + datas[1]);
    endwin();
    if(!datas[0].empty())add_to_log({datas[0], datas[1]});
    return 0;
}
