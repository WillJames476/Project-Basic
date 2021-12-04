#include "Message_list.h"

void Message_list::add_to_list(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
}

void Message_list::remove_from_list(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
}