#include "Todolist_model.h"

void Todolist_model::add_to_list(const std::string& account_name)
{
    tasks.emplace(std::make_pair(account_name, std::vector<Task>{}));
}

void Todolist_model::remove_from_list(const std::string& account_name)
{
    tasks.erase(account_name);
}

std::vector<Task> Todolist_model::get_item_from_list(const std::string& account_name) const
{
    return tasks.find(account_name)->second;
}

std::unordered_map<std::string, std::vector<Task>> Todolist_model::get_tasks() const
{
    return tasks;
}