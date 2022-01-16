#ifndef CONTACTS_LIST_H
#define CONTACTS_LIST_H

#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "../Utilities/List_crtp.h"
#include "Contacts.h"

class Contacts_list : public List_crtp<Contacts_list, Contacts>
{
    public:
        void add_item(const Contacts& to_add);
        void remove_item(const Contacts& to_remove);
        void print_items();
        Contacts get_item(const std::initializer_list<std::string>& datas) const;        
        Contacts get_item(const Contacts& to_find) const;
        
        friend std::ostream& operator<<(std::ostream& out, const Contacts_list& list);
        friend std::istream& operator>>(std::istream& in, Contacts_list& list);
	private:
		    std::vector<Contacts> contacts_list;
};

#endif
