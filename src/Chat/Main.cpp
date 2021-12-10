#include "Message_menu.h"
#include <chrono>
#include <array>
#include <sstream>

#include "../Utilities/Transmitter.h"

int main()
{
    std::array<std::string, 2> users{receive_data()};
    if(!users[0].empty() && users.size() == 2)
    {
        message("users/" + users[0] + "/"+ users[0] + "_chats.txt", users[1]);
        transmit_data(users[0] + " " + users[1]);
    }
    return 0;
}