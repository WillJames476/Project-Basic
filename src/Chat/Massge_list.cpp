#include <algorithm>
#include <sstream>
#include <iomanip>
#include "Message_list.h"

void Message_list::add_item(const Message_tuple& to_add)
{
    messages.push_back(to_add);
}

void Message_list::print_items()
{
    std::ostringstream output;

    for(const auto&x : messages)
    {
        auto message = x.get_tuple();

        output << "from: " << std::get<0>(message) << '\n' 
        << "-> "<< std::get<1>(message) 
        << std::put_time(std::localtime(&std::get<2>(message)), "-> %G\n\n" );
    }

    std::cout << output.str();
}

Message_list operator+(const Message_list& first
                        , const Message_list& second)
{
    Message_list temp{};
    std::merge(first.messages.begin(), first.messages.end(),
    second.messages.begin(), second.messages.end(),std::back_inserter(temp.messages));

    std::sort(temp.messages.begin(), temp.messages.end());
    return temp;
}

std::ostream& operator<<(std::ostream& out
                        , const Message_list& field)
{
    for(auto& send : field.messages) out << send;
    return out;
}

std::istream& operator>>(std::istream& in
                        , Message_list& field)
{
    Message_tuple to_receive{};
    while(in >> to_receive)
    field.messages.push_back(to_receive);
    return in;
}