#ifndef LIST_CTRTP_H
#define LIST_CRTP_H

#include <string>

template <typename X, typename T>
class List_crtp
{
	public:
		void add_to_list(const T& to_add);
		void add_to_list(const std::initializer_list<std::string>& datas);
		void remove_from_list(const T& to_remove);
		void remove_from_list(const std::initializer_list<std::string>& datas);
		T get_item_from_list(const std::initializer_list<std::string>& datas);
		T get_item_from_list(const T& to_find);
		void print_list();
};

template <typename X, typename T>
void List_crtp<X, T>::add_to_list(const T& to_add)
{
	static_cast<X&>(*this).add_item(to_add);
}

template <typename X, typename T>
void List_crtp<X, T>::add_to_list(const std::initializer_list<std::string>& datas)
{
	static_cast<X&>(*this).add_item(datas);
}

template <typename X, typename T>
void List_crtp<X, T>::remove_from_list(const T& to_remove)
{
	static_cast<X&>(*this).remove_item(to_remove);
}

template <typename X, typename T>
void List_crtp<X, T>::remove_from_list(const std::initializer_list<std::string>& datas)
{
	static_cast<X&>(*this).remove_item(datas);
}

template <typename X, typename T>
T List_crtp<X, T>::get_item_from_list(const std::initializer_list<std::string>& datas)
{
	return static_cast<X&>(*this).get_item(datas);
}

template <typename X, typename T>
T List_crtp<X, T>::get_item_from_list(const T& to_find)
{
	return static_cast<X&>(*this).get_item(to_find);
}

template <typename X, typename T>
void List_crtp<X, T>::print_list()
{
	static_cast<X&>(*this).print_items();
}

#endif