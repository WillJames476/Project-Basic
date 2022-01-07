#include <sstream>
#include <chrono>
#include <fstream>
#include <filesystem>
#include <array>
#include <vector>

#include "Message_list.h"
#include "Message_tuple.h"
#include "../Utilities/io.h"

void load_from_file(const std::array<std::string, 2>& file_name, 
Message_list& messages)
{
    if(!std::filesystem::exists("users/" + file_name[0] + "/chats"))
    {
        std::filesystem::create_directory("users/" + file_name[0] + "/chats");
    }

    try
    {
        std::fstream file_to_read("users/" + file_name[0] + "/chats/" 
        + file_name[0] + "_" + file_name[1] + ".txt", std::ios_base::in);
        file_to_read >> messages;
        file_to_read.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void message_control_flow(Message_list& messages, Message_list& temp, 
const std::string& acessor, char menu_choice, bool& menu_replay)
{
    switch(menu_choice)
    {
        case '1':
            messages.add_to_list
            (Message_tuple{acessor, get_string
            ("enter the message here:", REGEX_PREDICATES::MESSAGE),
            std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())});
            break;
        case '2':
            temp.print_list();
            break;
        case '3':
            menu_replay = false;
            break;
    }
}

char message_menu()
{
    std::ostringstream menu;
    menu<< "\n============================\n"
        << "1\tmake new message\n"
        << "2\tview chat\n"
        << "3\texit chat sector\n"
        << "enter your choice here: ";
    return get_integral<char>(menu.str(), '0', '4');
}

void message(const std::array<std::string,2>& users)
{
    Message_list subject{}, second{}, temp{};
    bool menu_replay{true};
    load_from_file({users[0], users[1]}, subject);
    load_from_file({users[1],users[0]}, second);
    
    while(menu_replay)    
    {
        temp = subject + second;
        message_control_flow(subject,temp, users[1], message_menu(),
        menu_replay);
    }

    std::string chat_file_name{"users/" + users[0] + "/chats/" 
    + users[0] + "_" + users[1] + ".txt"};
    
    save_to_file<Message_list>(chat_file_name, subject);
}