#include <iostream>
#include <algorithm>
#include "Communication_line.h"

void Communication_lines::add_to_list(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
    this->communication_lines.insert(datas[0]);
}

void Communication_lines::remove_from_list(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
    this->communication_lines.erase
    (std::find(this->communication_lines.begin(),this->communication_lines.end(),datas[0]));
}

std::string Communication_lines::get_item_from_list
(const std::initializer_list<std::string>& fields) const
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
    auto set_iter = this->communication_lines.find(datas[0]);

    if(set_iter != this->communication_lines.end()) return *set_iter;
    return std::string();
}

void Communication_lines::print_list()
{
    for(auto x : this->communication_lines)std::cout << x << '\n';
}