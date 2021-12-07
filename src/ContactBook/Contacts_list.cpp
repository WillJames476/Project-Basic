#include <array>
#include "Contacts_list.h"

void Contacts_list::add_to_list(const std::initializer_list<std::string>& fields)
{
    int counter{0};
    std::array<std::string,2>datas;
    for(auto& x : fields){datas[counter] = x;counter++;}
    this->contacts.insert(std::make_pair(datas[0], datas[1]));
}

void Contacts_list::remove_from_list(const std::initializer_list<std::string>& fields)
{
    int counter{0};
    std::array<std::string,2>datas;
    for(auto& x : fields){datas[counter] = x;counter++;}
    this->contacts.erase(datas[0]);
}

std::string Contacts_list::get_item_from_list(const std::initializer_list<std::string>& fields) const
{
    int counter{0};
    std::array<std::string,2>datas;
    for(auto& x : fields){datas[counter] = x;counter++;}

    std::string string_to_return{};

    auto item_iter = this->contacts.find(datas[0]);
    if(item_iter != this->contacts.end())
    string_to_return = item_iter->first + " " + item_iter->second + '\n';

    return string_to_return;
}

std::ostream& operator<<(std::ostream& out, const Contacts_list& list)
{
    for(const auto& sub : list.contacts)
    {out << sub.first + " " + sub.second + '\n';}; 
    return out;
}

std::istream& operator>>(std::istream& in, Contacts_list& list)
{
    std::array<std::string, 2> fields;
    while(in >> fields[0] >> fields[1]){list.add_to_list({fields[0], fields[1]});}
    return in;
}