#include "Todolist_model.h"

void Todolist_model::add_to_list(const std::string& account_name)
{
    tasks.emplace(account_name);
}

void Todolist_model::remove_from_list(const std::string& account_name)
{
    tasks.erase(account_name);
}