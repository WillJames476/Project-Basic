#ifndef COMMUNICATION_LINES_H
#define COMMUNICATION_LINES_H

#include<string>
#include<unordered_set>

class Communication_lines
{
    private:
        std::unordered_set<std::string>communication_lines;
    public:
        void add_to_list(const std::initializer_list<std::string>& fields);
        void remove_from_list(const std::initializer_list<std::string>& fields);
        std::string get_item_from_list(const std::initializer_list<std::string>& fields) const;
        void print_list();
};

#endif