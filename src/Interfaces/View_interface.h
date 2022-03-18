#ifndef VIEW_INTERFACE_H
#define VIEW_INTERFACE_H

#include <sstream>
#include <string>
#include <istream>

template <typename T>
class View_interface
{
public:

  std::string view_formatted() const;

  std::stringstream send_as_stream() const;

  void read_from_stream(std::istream& to_read) const;

private:

};

template <typename T>
std::string View_interface<T>::view_formatted() const
{
  return static_cast<T*>(this)->view_formatted();
}

template <typename T>
std::stringstream View_interface<T>::send_as_stream() const
{
  return static_cast<T*>(this)->send_as_stream();
}

template <typename T>
void View_interface<T>::read_from_stream(std::istream& to_read) const
{
  static_cast<T*>(this)->read_from_stream(to_read);
}

#endif
