#include <array>
#include <filesystem>

#include "Contacts_book_menu.h"
#include "../includes/Transmitter.h"
#include "../includes/loger.h"

int main(int argc, char**argv)
{
    std::array<std::string, 2>datas{receive_data()};

    if(!datas[0].empty() && std::filesystem::exists("users/" + datas[0]))
    {
        contacts_book_cli(argc, argv, "users/"+ datas[0] + "/" + datas[0] + "_cbook.txt");
        transmit_data(datas[0] + datas[1]);
        add_to_log({datas[0], datas[1], " contact books"});
    }

    return 0;
}