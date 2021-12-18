#include <sstream>
#include <array>

#include "Contacts.h"

Contacts::Contacts(const std::string& name, const std::string& number,
					const std::string& email)
: contact{name, number, email}
{
}

std::ostream& operator<< (std::ostream& out, const Contacts& to_give)
{
	std::ostringstream extractor;
	extractor << std::get<0>(to_give.contact)
			<< std::get<1>(to_give.contact)
			<< std::get<2>(to_give.contact) <<'\n';

	out << extractor.str();
	return out;
}

std::istream& operator>>(std::istream& in, Contacts& to_give)
{
	std::array<std::string,3> retreived_data;
	in >> retreived_data[0] >> retreived_data[1] >> retreived_data[2];
	Contacts copy{retreived_data[0], retreived_data[1], retreived_data[2]};
	to_give = copy;
	return in;
}
