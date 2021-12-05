#include <string>
#include <iostream>
#include "../Utilities/Transmitter.h"
#include "../Utilities/io.h"

int main()
{
    std::string received_data{receive_data()};
    std::cout << received_data << "exiting program\n";
    return 0;
}
