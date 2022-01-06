#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cerrno>
#include <filesystem>
/*
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/string.hpp>
*/
#include "Transmitter.h"

void transmit_data(const std::string& data_to_transfer)
{
    if(std::filesystem::exists("tmp/cows"))
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
    else
    {
        std::cerr << "pipe is non existent\n";
    }
}

std::array<std::string,2> receive_data()
{
    std::array<std::string,2> strings_to_return;
    char datas[32];

    if(std::filesystem::exists("tmp/cows"))
    {
        int transmission = open("tmp/cows", O_RDWR);
    
        if(read(transmission, datas, 32) == -1)
        {
            std::cerr << strerror(errno) << '\n';
        }
    
        close(transmission);
        std::istringstream(datas) >> strings_to_return[0] >> strings_to_return[1];
    }
    else
    {
        std::cerr << "pipe is non existent\n";
    }

    return strings_to_return;
}

/*
void transmit_data_s(const std::string& datas)
{
	using namespace boost::interprocess;
	managed_shared_memory sh_mem{open_or_create, "RADIO", 1024};
	sh_mem.construct<string>("DATA")(datas);
}

std::array<std::string, 2> receive_data_s()
{
	using namespace boost::interprocess;
	managed_shared_memory sh_mem{open_or_create, "RADIO", 1024};
	auto x = sh_mem.find<string>("DATA");
    sh_mem.destroy<string>("RADIO");

	std::stringstream buffer;
    buffer << *x.first;
	std::array<std::string, 2 >string_to_return_arr;
	buffer >> string_to_return_arr[0] >> string_to_return_arr[1];

	return string_to_return_arr;
}
*/