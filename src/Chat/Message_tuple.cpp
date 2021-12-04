#include <vector>
#include <sstream>
#include <iostream>
#include <array>
#include "Message_tuple.h"

Message_tuple::Message_tuple(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
    this->message = std::make_tuple(datas[0], datas[1], std::stol(datas[2]));
}

void Message_tuple::print_message()
{
    std::ostringstream to_print;
    to_print << std::get<0>(this->message) << " " 
    << std::get<1>(this->message) << " "
    << std::asctime(std::localtime(&std::get<2>(this->message))) << '\n';
    std::cout << to_print.str();
}

std::ostream& operator<<(std::ostream& out, const Message_tuple& fields)
{
    out << std::get<0>(fields.message) 
    << " " << std::get<1>(fields.message) 
    << " " << std::get<2>(fields.message) << '\n';
    return out;
}
std::istream& operator>>(std::istream& in, Message_tuple& fields)
{
    std::array<std::string, 3> datas;
    in >> datas[1] >> datas[2] >> datas[3];
    fields.message = std::move(std::make_tuple(datas[1], datas[2], std::stol(datas[3])));
    return in;
}