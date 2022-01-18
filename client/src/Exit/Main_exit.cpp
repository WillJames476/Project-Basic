#include <string>
#include <array>
#include <filesystem>

#include "../includes/Transmitter.h"
#include "../includes/io.h"
#include "../includes/loger.h"
#include "Exitui.h"

int main()
{
    std::array<std::string,2>datas{receive_data()};
    exit_ui(datas[0] + " " + datas[1]);
    
    if(!datas[0].empty() && std::filesystem::exists("users/" + datas[0]))
    {
        add_to_log({datas[0], datas[1], " exit sector"});
    }

    return 0;
}
