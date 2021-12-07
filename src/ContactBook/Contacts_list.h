#ifndef CONTACTS_LIST_H
#define CONTACTS_LIST_H

#include <string>
#include <map>
#include <iostream>

#include "../Utilities/List_management.h"

class Contacts_list : public List_management
{
    private:
        std::map<std::string, std::string> contacts;
    public:
        void add_to_list(const std::initializer_list<std::string>& fields);
        void remove_from_list(const std::initializer_list<std::string>& fields);
        std::string get_item_from_list(const std::initializer_list<std::string>& fields) const;

        friend std::ostream& operator<<(std::ostream& out, const Contacts_list& list);
        friend std::istream& operator>>(std::istream& in, Contacts_list& list);
};

#endif