#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#include <iostream>
#include <cstdio>
#include <cstring>
#include "Transmitter.h"

void transmit_data(const std::string& data_to_transfer)
{
    char make[32];
    strncpy(make,data_to_transfer.c_str(),31);
    mkfifo("tmp/cows", 0777);
    int transmission = open("tmp/cows", O_WRONLY);
    write(transmission,make,32);
    close(transmission);
    std::cout << transmission << '\n';
}

std::string receive_data()
{
    char datas[32];
    int transmission = open("tmp/cows", O_RDONLY);
    read(transmission, datas, 32);
    close(transmission);
    return datas;
}