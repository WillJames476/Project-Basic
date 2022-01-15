#ifndef TODOLIST_MENU_H
#define TODOLIST_H

#include <string>
#include <array>

//void task_manager(const std::array<std::string,2>& user_file);
void task_manager_cli(int argc, char** argv
                    ,const std::array<std::string,2>& acces_descriptor);
#endif