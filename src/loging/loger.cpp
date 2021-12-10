#include <fstream>
#include <vector>
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "loger.h"

void add_to_log(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string>datas;
    for(auto persons : fields)datas.push_back(persons);

    try
    {
        std::fstream loging
        ("users/" + datas[0] + "/" + datas[0] + "_logs.txt", std::ios_base::app);

        std::stringstream to_write;
        std::time_t current_time = std::chrono::system_clock::to_time_t
        (std::chrono::system_clock::now());
        
        to_write << datas[0] << " " << datas[1] << " "
        << std::put_time(std::localtime(&current_time),"%OH-%m, %d-%B%") << '\n';

        loging << to_write.str();
        loging.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }    
}