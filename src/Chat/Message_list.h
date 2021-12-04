#ifndef MESSAGE_LIST_H
#define MESSAGE_LIST_H

#include <vector>
#include "Message_tuple.h"
#include "../Utilities/List_management.h"

class Message_list : public List_management
{
    private:
        std::vector<Message_tuple>messages;
    public:
        void add_to_list(const std::initializer_list<std::string>& fields);
        void remove_from_list(const std::initializer_list<std::string>& fields);
};  

#endif