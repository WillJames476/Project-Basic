#ifndef TODOLIST_CONTROL_H
#define TODOLIST_CONTROL_H

#include <string>
#include <memory>
#include "Todolist_model.h"
#include "../Interfaces/Control_interface.h"

class Todolist_control : public Control_interface<Todolist_control>
{
public:

  Todolist_control(const std::shared_ptr<Todolist_model>& model);

  bool add_to_list(const std::initializer_list<std::string>& fields) const;

  bool add_to_list_task(const std::initializer_list<std::string>& fields) const;

  bool remove_from_list(const std::initializer_list<std::string>& fields) const;

  bool remove_from_list_task(const std::initializer_list<std::string>& fields) const;

private:

  std::shared_ptr<Todolist_model>model_ptr;
  
};

#endif
