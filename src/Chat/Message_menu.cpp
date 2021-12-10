#include <sstream>
#include <chrono>
#include <fstream>
#include <filesystem>
#include <array>

#include "Message_list.h"
#include "Message_menu.h"
#include "../Utilities/io.h"

void save_to_file(const std::array<std::string, 2>& file_name, 
Message_list& messages)
{
    try
    {
        std::fstream file_to_read("users/" + file_name[0] + "/chats/" 
        + file_name[0] + "_" + file_name[1] + ".txt", std::ios_base::out);
        file_to_read << messages;
        file_to_read.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    } 
}

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

void message_control_flow(Message_list& messages, const Message_list& temp, 
const std::string& acessor, char menu_choice, bool& menu_replay)
{
    switch(menu_choice)
    {
        case '1':
            messages.add_to_list
            ({acessor, get_string
            ("enter the message here:", string_predicates("Message")),
            std::to_string(std::chrono::system_clock::to_time_t
            (std::chrono::system_clock::now()))});
            break;
        case '2':
            std::cout << temp;
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

    save_to_file({users[0],users[1]}, subject);
}