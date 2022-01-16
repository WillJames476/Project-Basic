#ifndef CONTACTS_H
#define CONTACTS_H

#include <tuple>
#include <string>
#include <iostream>

class Contacts
{
	public:
		Contacts() = default;
		Contacts(const std::string& name, const std::string& number, 
				const std::string& email);
		Contacts& operator=(const Contacts& to_copy) = default;
		~Contacts() = default;	
		void print_item();

		friend bool operator== (const Contacts& right, const Contacts& left);
		friend std::ostream& operator<<(std::ostream& out, const Contacts& to_give);
		friend std::istream& operator>>(std::istream& in, Contacts& to_modify);

	private:
		std::tuple<std::string, std::string, std::string> contact;
};

#endif
