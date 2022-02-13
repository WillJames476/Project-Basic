#include <algorithm>
#include "Todolist_model.h"

void Todolist_model::add_to_list(const std::string& account_name)
{
    tasks.emplace(std::make_pair(account_name, std::vector<Task>{}));
}

void Todolist_model::add_to_list_task(const std::string& account_target
                                    , const std::string& task_name
                                    , const std::string& account_source)
{
    tasks.find(account_target)->second.push_back(Task{task_name, account_source});
}

void Todolist_model::remove_from_list_task(const std::string& account_target
                                        , const std::string& task_name
                                        , const std::string& account_source)
{
    const auto& location{tasks.find(account_target)};

    if(location != std::end(tasks))
    {
        auto& task_list{location->second};

        std::remove_if(std::begin(task_list), std::end(task_list)
            , [&](const auto& x)
            {
                bool is_account_same    {x.task_giver_str == account_source}
                    , is_task_name_same {x.task_name_str == task_name};

                return is_account_same && is_task_name_same;
            });
    }
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