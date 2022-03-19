#ifndef CONTROL_INTERFACE_H
#define CONTROL_INTERFACE_H

#include <string>

template <typename T>
class Control_interface
{
public:

  bool add_to_list(const std::initializer_list<std::string>& fields) const;

  bool remove_from_list(const std::initializer_list<std::string>& fields) const;

  std::string get_item_from_list(const std::initializer_list<std::string>& fields) const;

private:

  
};

template <typename T>
bool Control_interface<T>::add_to_list(const std::initializer_list<std::string>& fields) const
{
  return static_cast<T*>(this)->add_to_list(fields);
}

template <typename T>
bool Control_interface<T>::remove_from_list(const std::initializer_list<std::string>& fields) const
{
  return static_cast<T*>(this)->remove_from_list(fields);
}

template<typename T>
std::string Control_interface<T>::get_from_list(const std::initializer_list<std::string>& fields) const
{
  return static_cast<T*>(this)->get_from_list(fields);
}

#endif
