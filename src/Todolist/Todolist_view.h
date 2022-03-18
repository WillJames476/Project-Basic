#ifndef TODOLIST_VIEW_H
#define TODOLIST_VIEW_H

#include <memory>
#include <string>
#include <sstream>
#include <istream>

#include "Todolist_model.h"
#include "../Interfaces/View_interface.h"

class Todolist_view : public View_interface<Todolist_view>
{
public:

  Todolist_view(const std::shared_ptr<Todolist_model>& model);

  std::string send_formatted(const std::string& account_name) const;

  std::ostringstream send_as_stream() const;

  void read_from_stream(std::istream& to_read) const;

private:

  std::shared_ptr<Todolist_model> model_ptr;
};

#endif
