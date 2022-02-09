#ifndef COMMLINE_CONTROL_H
#define COMMLINE_CONTROL_H

#include <memory>
#include "Commline_model.h"

class Commline_control
{
    public:
        Commline_control(const std::shared_ptr<Commline_model>& model);

        void add_to_list(const std::initializer_list<std::string>& fields);
        void remove_from_list(const std::initializer_list<std::string>& fields);
        
    private:
        std::shared_ptr<Commline_model> model_ptr;
};

#endif