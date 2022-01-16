#ifndef MESSAGE_LIST_H
#define MESSAGE_LIST_H

#include <vector>
#include "Message_tuple.h"
#include "../includes/List_crtp.h"

class Message_list : public List_crtp<Message_list, Message_tuple>
{
    public:
        Message_list() = default;

        void add_item(const Message_tuple& message);
        void print_items();

        friend Message_list operator+(const Message_list& first, const Message_list& second);
        friend std::ostream& operator<<(std::ostream& out,const Message_list& field);
        friend std::istream& operator>>(std::istream& in, Message_list& field);

	private:
		std::vector<Message_tuple> messages;
};

#endif
