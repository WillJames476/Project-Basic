#ifndef COMMLINE_VIEW_H
#define COMMLINE_VIEW_H

#include <memory>
#include <string>
#include <sstream>
#include <istream>
#include <interfaces/View_interface.hpp>

#include "Commline_model.h"


class Commline_view : public View_interface<Commline_view>
{
public:

  Commline_view(const std::shared_ptr<Commline_model>& model);

  std::string
  send_formatted(const std::string& account) const;

  std::ostringstream
  send_as_stream () const;

  void
  read_from_stream(std::istream& to_read) const;

private:

  std::shared_ptr<Commline_model> model_ptr;
};

#endif
