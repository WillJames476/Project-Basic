#include <sstream>
#include <chrono>
#include <fstream>
#include <filesystem>

#include "Message_list.h"
#include "Message_menu.h"
#include "../Utilities/io.h"

void save_to_file(const std::string& file_name, Message_list& messages)
{
    try
    {
        std::fstream file_to_read(file_name, std::ios_base::out);
        file_to_read << messages;
        file_to_read.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    } 
}

void load_from_file(const std::string& file_name, Message_list& messages)
{
    try
    {
        std::fstream file_to_read(file_name, std::ios_base::in);
        file_to_read >> messages;
        file_to_read.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void message_control_flow(Message_list& messages, const std::string& acessor,
char menu_choice, bool& menu_replay)
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
            messages.print_list(acessor);
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

void message(const std::string& file_name, const std::string& accesor)
{
    Message_list subject{};
    bool menu_replay{true};

    load_from_file(file_name, subject);

    while(menu_replay)
    {
        message_control_flow(subject, accesor, message_menu(),
        menu_replay);
    }

    save_to_file(file_name, subject);
}