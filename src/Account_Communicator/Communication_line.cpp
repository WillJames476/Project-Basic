#include <iostream>
#include <algorithm>
#include <filesystem>
#include "../Utilities/io.h"
#include "Communication_line.h"

void Communication_lines::add_to_list(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
    if(std::filesystem::exists("users/" + datas[0]))
    this->communication_lines.insert
    (std::make_pair(datas[0],std::stoi(datas[1])));
}

void Communication_lines::remove_from_list(const std::initializer_list<std::string>& fields)
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
    this->communication_lines.erase(this->communication_lines.find(datas[0]));
}

std::string Communication_lines::get_item_from_list
(const std::initializer_list<std::string>& fields) const
{
    std::vector<std::string> datas;
    for(auto x : fields)datas.push_back(x);
    auto set_iter = this->communication_lines.find(datas[0]);

    if(set_iter != this->communication_lines.end() && set_iter->second) 
    {return set_iter->first;}
    return std::string();
}

std::ostream& operator<<(std::ostream& out,const Communication_lines& lines)
{
    for(auto x : lines.communication_lines){out << x.first << ' ' << x.second << '\n';}
    return out;
}

std::istream& operator>>(std::istream& in, Communication_lines& lines)
{
    std::string accounts, verification;
    while(in >> accounts >> verification){lines.add_to_list({accounts, verification});}
    return in;
}