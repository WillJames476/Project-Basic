#include "Message_menu.h"
#include <chrono>
#include <array>
#include <sstream>

#include "../Utilities/Transmitter.h"

int main()
{
    std::array<std::string, 2> users;
    std::istringstream(receive_data()) >> users[0] >> users[1];

    if(!users[0].empty())
    {
        message("users/senna/senna_chats.txt", users[1]);
        transmit_data(users[0] + " " + users[1]);
    }
    return 0;
}