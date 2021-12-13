#include <algorithm>
#include "Message_list.h"

void Message_list::add_to_list(const std::string& user, const std::string& message,
const long time)
{
    this->messages.push_back(Message_tuple(user, message, time));
}

Message_list operator+(const Message_list& first, const Message_list& second)
{
    Message_list temp{};
    for(auto received : first.messages)temp.messages.push_back(received);
    for(auto received : second.messages)temp.messages.push_back(received);
    std::sort(temp.messages.begin(), temp.messages.end());

    return temp;
}

std::ostream& operator<<(std::ostream& out, const Message_list& field)
{
    for(auto& send : field.messages) out << send;
    return out;
}

std::istream& operator>>(std::istream& in, Message_list& field)
{
    Message_tuple to_receive{};
    while(in >> to_receive)
    field.messages.push_back(to_receive);
    return in;
}