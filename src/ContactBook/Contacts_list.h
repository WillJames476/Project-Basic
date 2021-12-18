#ifndef CONTACTS_LIST_H
#define CONTACTS_LIST_H

#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "Contacts.h"

class Contacts_list 
{
    public:
		void add_to_list(const Contacts& to_add);
        void remove_from_list(const std::string& name_to_erase);
        std::string get_item_from_list(const std::string& name_to_find) const;

        friend std::ostream& operator<<(std::ostream& out, const Contacts_list& list);
        friend std::istream& operator>>(std::istream& in, Contacts_list& list);

	private:
		std::vector<Contacts> contacts_list;
};

#endif
