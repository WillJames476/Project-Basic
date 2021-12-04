#include <vector>
#include <sstream>
#include <iostream>
#include "Message_tuple.h"

Message_tuple::Message_tuple(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
    std::chrono::month_day x{std::chrono::July / std::stoi(datas[3])};
    this->message = std::make_tuple(datas[0], datas[1], x);
}

void Message_tuple::print_message()
{
    std::ostringstream to_print;
    to_print << std::get<0>(this->message) << " " 
    << static_cast<unsigned int>(std::get<2>(this->message).month()) << '\n';
    std::cout << to_print.str();
}