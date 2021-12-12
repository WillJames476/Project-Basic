#ifndef LIST_FUNCTIONALITIES_H
#define LIST_FUNCTIONALITIES_H

#include <vector>
#include <algorithm>

template<typename C>
void add_to_list(std::vector<C>& list_adt,const C& to_add)
{
    list_adt.push_back(to_add);
}

template<typename C>
void remove_from_list(std::vector<C>& list_adt,const C& to_remove)
{
    list_adt.erase(std::find(list_adt.begin(), list_adt.end(), to_remove));
}

template<typename C>
C get_item_from_list(std::vector<C>& list_adt, const C& to_get)
{
    return list_adt
    [std::distance(list_adt.begin(), 
    std::find(list_adt.begin(), list_adt.end(), to_get))];
}

#endif