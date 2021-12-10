#include <curses.h>
#include "Exitui.h"

void exit_ui(const std::string& info_to_show)
{
    WINDOW* win = newwin(10,70,0,0);
    refresh();
    box(win,0,0);
    mvwprintw(win,0,3,"Exiter");

    wrefresh(win);
    mvwprintw(win,2,2, "%s exiting program\n",info_to_show.c_str());

    mvwprintw(win,4,2, "press any key to exit:");
    mvwprintw(win,9,60, "Set last");
    wrefresh(win);
    mvwgetch(win,4,25);
}