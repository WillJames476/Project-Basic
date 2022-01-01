#ifndef MESSAGE_TUPLE_H
#define MESSAGE_TUPLE_H

#include <iostream>
#include <ctime>
#include <tuple>
#include <string>

class Message_tuple
{
    public:
        Message_tuple();
        Message_tuple(const Message_tuple& copy) = default;
        Message_tuple(const std::string& user, const std::string& message,const long time);
        std::tuple<std::string, std::string, std::time_t> get_tuple() const;

        friend bool operator< (const Message_tuple& first, const Message_tuple& last);
        friend std::ostream& operator<<(std::ostream& out, const Message_tuple& fields);
        friend std::istream& operator>>(std::istream& in, Message_tuple& fields);

	private:
		std::tuple<std::string, std::string, std::time_t> message;
};

#endif
