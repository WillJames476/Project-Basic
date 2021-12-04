#ifndef MESSAGE_TUPLE_H
#define MESSAGE_TUPLE_H

#include <iostream>
#include <ctime>
#include <tuple>
#include <string>

class Message_tuple
{
    private:
        std::tuple<std::string, std::string, std::time_t> message;
    public:
        Message_tuple();
        Message_tuple(const std::initializer_list<std::string>& fields);
        void print_message();
        
        friend bool operator< (const Message_tuple& first, const Message_tuple& last);
        friend std::ostream& operator<<(std::ostream& out, const Message_tuple& fields);
        friend std::istream& operator>>(std::istream& in, Message_tuple& fields);
};

#endif