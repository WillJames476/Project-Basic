#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <string>
#include <array>

void transmit_data(const std::string& data);
std::array<std::string,2> receive_data();

#endif