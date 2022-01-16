#include <array>
#include <sstream>

#include "Contacts_list.h"

void Contacts_list::add_item(const Contacts& to_add)
{
	contacts_list.push_back(to_add);
}

void Contacts_list::remove_item(const Contacts& to_remove)
{
	contacts_list.erase(std::find(contacts_list.begin(), contacts_list.end(), to_remove));
}

void Contacts_list::print_items()
{
	for(auto& data : contacts_list)
	{
		data.print_item();
	}
}

Contacts Contacts_list::get_item(const std::initializer_list<std::string>& datas) const
{
	int tracker = 0;
	std::array<std::string, 3> retrieved;
	
	for(const auto& x : datas)
	{
		retrieved[tracker] = x;
		++tracker;
	}

	auto item = std::find(contacts_list.begin(), contacts_list.end(), 
	Contacts{retrieved[0], retrieved[1], retrieved[2]});

	if(item != contacts_list.end())
	{
		return contacts_list[std::distance(contacts_list.begin(),(item))];
	}

	std::cerr << "item is not found\n";
	return Contacts{};
}

Contacts Contacts_list::get_item(const Contacts& to_find) const
{
	auto item = std::find(contacts_list.begin(), contacts_list.end(), to_find);

	if(item != contacts_list.end())
	{
		return contacts_list[std::distance(contacts_list.begin(), item)];
	}

	std::cerr << "item is not found\n";
	return Contacts{};
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
