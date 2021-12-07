#include <array>
#include <sstream>

#include "Contacts_book_menu.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::string received_data{receive_data()};
    std::array<std::string, 2>datas;

    std::istringstream(received_data) >> datas[0] >> datas[1]; 
    contacts_book("users/"+ datas[0] + "/" + datas[0] + "_cbook.txt");
    transmit_data(received_data);  
    return 0;
}