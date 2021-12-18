#include <array>
#include <sstream>

#include "Contacts_list.h"

void Contacts_list::add_to_list(const Contacts& to_add)
{
	contacts_list.push_back(to_add);
}

void Contacts_list::remove_from_list(const std::string& name_to_erase)
{
	contacts_list.erase(std::find(contacts_list.begin(), contacts_list.end(), name_to_erase));
}

std::string Contacts_list::get_item_from_list(const std::string& name_to_find) const
{
    std::ostringstream string_to_return{};
    auto item_iter = std::find(contacts_list.begin(), contacts_list.end(), name_to_find);

	if(item_iter != contacts_list.end())
	{
		string_to_return << contacts_list[std::distance(contacts_list.begin(),item_iter)];
	}

	return string_to_return.str();
}


std::ostream& operator<<(std::ostream& out, const Contacts_list& list)
{
    for(const auto& sub : list.contacts_list)
    {out << sub;}
    return out;
}

std::istream& operator>>(std::istream& in, Contacts_list& list)
{
	Contacts temp{};
    while(in >> temp){list.add_to_list(temp);}
    return in;
}
