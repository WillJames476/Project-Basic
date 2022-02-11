#ifndef TODOLIST_CONTROL_H
#define TODOLIST_CONTROL_H

#include <memory>
#include "Todolist_model.h"

class Todolist_control
{
    public:
        Todolist_control(const Todolist_model& model);

    private:
        std::shared_ptr<Todolist_model>model_ptr;
};

#endif