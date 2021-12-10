#include <array>
#include <sstream>

#include "Contacts_book_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::array<std::string, 2>datas{receive_data()};

    if(!datas[0].empty())
    {
        contacts_book("users/"+ datas[0] + "/" + datas[0] + "_cbook.txt");
        transmit_data(datas[0] + datas[1]);
    }

    return 0;
}