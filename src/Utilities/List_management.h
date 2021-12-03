#ifndef LIST_MANAGEMENT_H
#define LIST_MANAGEMENT_H

class List_management
{
    public:
        virtual void add_to_list(const std::initializer_list<std::string>& fields) = 0;
        virtual void remove_from_list(const std::initializer_list<std::string>& fields) = 0;
};

#endif