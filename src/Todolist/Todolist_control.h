#ifndef TODOLIST_CONTROL_H
#define TODOLIST_CONTROL_H

#include <string>
#include <memory>
#include "Todolist_model.h"

class Todolist_control
{
    public:
        Todolist_control(const std::shared_ptr<Todolist_model>& model);

        void add_to_list(const std::initializer_list<std::string>& fields) const;

        void remove_from_list(const std::initializer_list<std::string>& fields) const;        

    private:
        std::shared_ptr<Todolist_model>model_ptr;
};

#endif