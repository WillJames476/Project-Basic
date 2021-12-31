#include <sstream>
#include <array>


#include "Contacts.h"

Contacts::Contacts(const std::string& name, const std::string& number,
					const std::string& email)
: contact{name, number, email}
{
}

void Contacts::print_item()
{
	std::ostringstream output;
	output << "name: " << std::get<0>(contact) << ' '
	<< "\tnumber: " << std::get<1>(contact) << ' '
	<< "\temail: " << std::get<2>(contact) << '\n';

	std::cout << output.str();
}

bool operator== (const Contacts& right, const Contacts& left)
{
	bool is_equal = std::get<0>(left.contact) == std::get<0>(right.contact) &&
	std::get<1>(left.contact) == std::get<1>(right.contact) &&
	std::get<2>(left.contact) == std::get<2>(right.contact);

	return is_equal;
}

std::ostream& operator<< (std::ostream& out, const Contacts& to_give)
{
	std::ostringstream extractor;
	extractor << std::get<0>(to_give.contact) << " "
			<< std::get<1>(to_give.contact) << " "
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
