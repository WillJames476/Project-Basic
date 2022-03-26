#include "Task.h"

Task::Task(const std::string& task_name,
	   const std::string& task_giver)
  : task_name_str{task_name},
    task_giver_str{task_giver}
{
}
