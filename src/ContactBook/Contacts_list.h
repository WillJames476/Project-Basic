#ifndef CONTACTS_LIST_H
#define CONTACTS_LIST_H

#include <string>
#include <map>
#include <iostream>

class Contacts_list 
{
    private:
        std::map<std::string, std::string> contacts;
    public:
        void add_to_list(const std::string& name, const std::string number);
        void remove_from_list(const std::string& name_to_erase);
        std::string get_item_from_list(const std::string& name_to_find) const;
        
        friend std::ostream& operator<<(std::ostream& out, const Contacts_list& list);
        friend std::istream& operator>>(std::istream& in, Contacts_list& list);
};

#endif