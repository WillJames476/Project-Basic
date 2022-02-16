#ifndef TODOLIST_VIEW_H
#define TODOLIST_VIEW_H

#include <memory>
#include <string>

#include "Todolist_model.h"

class Todolist_view
{
    public:
        Todolist_view(const std::shared_ptr<Todolist_model>& model);

		std::string send_formatted(const std::string& account_name) const;

    private:
        std::shared_ptr<Todolist_model> model_ptr;
};

#endif
