#include "Task.h"

Task::Task(const std::string& task_name
        , const std::string& task_giver)
    : task_name_str{task_name}
    , task_giver_str{task_giver}
{
}

std::string Task::get_task_name() const
{
    return task_name_str;
}

std::string Task::get_task_giver() const
{
    return task_giver_str;
}