#ifndef TODOLIST_VIEW_H
#define TODOLIST_VIEW_H

#include <memory>
#include "Todolist_model.h"

class Todolist_model
{
    public:
        Todolist_model(const Todolist_model& model);

    private:
        std::shared_ptr<Todolist_model> model_ptr;
};

#endif