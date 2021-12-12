#ifndef LIST_FUNCTIONALITIES_H
#define LIST_FUNCTIONALITIES_H

#include <vector>

template<typename C>
void add_to_list(std::vector<C>& list_adt,const C& to_add)
{
    list_adt.push_back(to_add);
}

#endif