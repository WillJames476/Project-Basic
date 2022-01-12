#ifndef MESSAGE_MENU_H
#define MESSAGE_MENU_H

#include <string>
#include <array>

void message(const std::array<std::string,2>& users);
void message_cli(int argc, char** argv, const std::array<std::string, 2>& users);

#endif