#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cerrno>

#include "Transmitter.h"

void transmit_data(const std::string& data_to_transfer)
{
    char make[32];
    strncpy(make,data_to_transfer.c_str(),31);
    int transmission = open("tmp/cows", O_RDWR);
    
    if(write(transmission,make,32) == -1)
    {
        std::cerr << strerror(errno) << '\n';
    }
    
    close(transmission);
}

std::array<std::string,2> receive_data()
{
    char datas[32];
    int transmission = open("tmp/cows", O_RDWR);
    
    if(read(transmission, datas, 32) == -1)
    {
        std::cerr << strerror(errno) << '\n';
    }

    close(transmission);
    mkfifo("tmp/cows", 0000);
    
    std::array<std::string,2> strings_to_return;
    std::istringstream(datas) >> strings_to_return[0] >> strings_to_return[1];
    
    return strings_to_return;
}