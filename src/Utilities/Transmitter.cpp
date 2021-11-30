#include <fstream>
#include "Transmitter.h"

void transmit_data(const std::string& data_to_transfer)
{
    std::ofstream transmit_data("tmp/transmitter.txt");
    transmit_data << data_to_transfer;
    transmit_data.close();
}

std::string receive_data()
{
    std::string data_to_receive;
    std::ifstream get_data("tmp/transmitter.txt");
    get_data >> data_to_receive;
    return data_to_receive;
}