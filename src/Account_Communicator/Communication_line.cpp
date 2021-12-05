#include <iostream>
#include <algorithm>
#include <filesystem>
#include <fstream>

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

void Communication_lines::alter_permission(const std::string& user_curent, 
const std::string& user_target)
{
    std::cout << user_curent << user_target << '\n';
    Communication_lines temp;
    load_from_file("users/" + user_target + "/" + user_target + "_comms.txt", temp);
    alter_boolean(user_curent, temp);
    save_to_file("users/" + user_target + "/" + user_target + "_comms.txt", temp);
}

void load_from_file(const std::string& file_name, Communication_lines& lines)
{
    try
    {
        std::ifstream file_to_load(file_name);
        file_to_load >> lines;
        file_to_load.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void save_to_file(const std::string& file_name, const Communication_lines& lines)
{
    try
    {
        std::ofstream file_to_save(file_name);
        file_to_save << lines;
        file_to_save.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void alter_boolean(const std::string& user_curent, 
Communication_lines& user_target)
{
    auto map_iter = user_target.communication_lines.find(user_curent);

    if(map_iter != user_target.communication_lines.end()) 
    {map_iter->second = map_iter->second ? false : true;}
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