#include <string>
#include <iostream>
#include <array>
#include <sstream>

#include "../Utilities/Transmitter.h"
#include "../Utilities/io.h"
#include "../loging/loger.h"

int main()
{
    std::string received_data{receive_data()};
    std::array<std::string,2>datas;

    std::istringstream(received_data) >> datas[0] >> datas[1];
    std::cout << received_data << " " << "exiting program\n";
    add_to_log({datas[0], datas[1]});
    return 0;
}
