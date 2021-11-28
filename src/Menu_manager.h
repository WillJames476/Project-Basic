#ifndef MENU_MANAGER_H
#define MENU_MANAGER_H

#include <string>
#include <ctime>

#include "task_list.h"

void task_manager(const std::string& user_file);
std::string accounts_manager(const std::string& accounts_file);

#endif