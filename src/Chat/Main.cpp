#include "Message_menu.h"
#include <array>
#include <string>
#include <filesystem>

#include "../Utilities/Transmitter.h"
#include "../loging/loger.h"

int main()
{
    std::array<std::string, 2> users{receive_data()};
    
    if(!users[0].empty() && std::filesystem::exists("users/" + users[0]))
    {
        message(users);
        transmit_data(users[0] + " " + users[1]);
        add_to_log({users[0], users[1], " chat sector"});
    }
    return 0;
}