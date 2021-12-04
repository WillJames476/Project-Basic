#ifndef MESSAGE_TUPLE_H
#define MESSAGE_TUPLE_H

#include <chrono>
#include <ctime>
#include <tuple>
#include <string>

class Message_tuple
{
    private:
        std::tuple<std::string, std::string, std::chrono::month_day> message;
    public:
        Message_tuple(const std::initializer_list<std::string>& fields);
        void print_message();    
};

#endif