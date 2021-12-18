#ifndef MESSAGE_LIST_H
#define MESSAGE_LIST_H

#include <vector>
#include "Message_tuple.h"

class Message_list
{
    public:
        Message_list() = default;
        void add_to_list(const std::string& user, const std::string& message,const long time);

        friend Message_list operator+(const Message_list& first, const Message_list& second);
        friend std::ostream& operator<<(std::ostream& out,const Message_list& field);
        friend std::istream& operator>>(std::istream& in, Message_list& field);

	private:
		std::vector<Message_tuple> messages;
};

#endif
