#include <algorithm>
#include "Message_list.h"

void Message_list::add_to_list(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto& x : fields)datas.push_back(x);
    this->messages.push_back(Message_tuple({datas[0], datas[1], datas[2]}));
}

void Message_list::remove_from_list(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto& x : fields)datas.push_back(x);
    auto x = Message_tuple{datas[0], datas[1], datas[2]};
    this->messages.erase(std::upper_bound(this->messages.begin(), this->messages.end(), x));
}

void Message_list::print_list(const std::string& name_of_user)
{
    for(auto& x : this->messages)
    {
        if(x.get_name() == name_of_user)x.print_message();   
    }
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