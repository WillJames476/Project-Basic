#include <array>
#include "Contacts_list.h"

void Contacts_list::add_to_list(const std::string& name, const std::string number)
{
    this->contacts.insert(std::make_pair(name, number));
}

void Contacts_list::remove_from_list(const std::string& name_to_erase)
{
    this->contacts.erase(name_to_erase);
}

std::string Contacts_list::get_item_from_list(const std::string& name_to_find) const
{
    std::string string_to_return{};
    auto item_iter = this->contacts.find(name_to_find);

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
    while(in >> fields[0] >> fields[1]){list.add_to_list(fields[0], fields[1]);}
    return in;
}