#include <string>
#include <iostream>
#include "../Utilities/Transmitter.h"

int main()
{
    std::string received_data{receive_data()};
    std::cout << received_data << '\n';
    return 0;
}