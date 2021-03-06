#include <algorithm>
#include "Todolist_model.h"
#include <iostream>

bool
Todolist_model::add_to_list(const std::string& account_name)
{

  if(tasks.find(account_name) == std::end(tasks))
    {
      tasks.emplace(std::make_pair(account_name, std::vector<Task>{}));
      return true;
    }

  return false;
}

bool
Todolist_model::add_to_list_task(const std::string& account_target,
				 const std::string& account_source,
				 const std::string& task_name)
{
  auto target_location {tasks.find(account_target)};
    
  if(target_location != std::end(tasks))
    {
      target_location->second.push_back(Task{task_name, account_source});

      return true;
    }

  return false;
}

bool
Todolist_model::remove_from_list(const std::string& account_name)
{
  if(tasks.find(account_name) != std::end(tasks))
    {
      tasks.erase(account_name);
      return true;
    }

  return false;
}

bool
Todolist_model::remove_from_list_task(const std::string& account_target,
				      const std::string& task_name,
				      const std::string& account_source)
{
  const auto& location{tasks.find(account_target)};

  if(location != std::end(tasks))
    {
      auto& task_list{location->second};
      
      task_list.erase
	(std::remove_if(std::begin(task_list), std::end(task_list),
			[&](const auto& x)
			{
			  bool is_account_same    {x.task_giver_str == account_source};
			  bool is_task_name_same  {x.task_name_str == task_name};

			  return is_account_same && is_task_name_same;
			}));
      return true;
    }

  return false;
}

std::vector<Task>
Todolist_model::get_item_from_list(const std::string& account_name) const
{
  const auto& list_extract{tasks.find(account_name)};

  if(list_extract != std::end(tasks))
    {
      return list_extract->second;
    }

  return std::vector<Task>{};
}

std::unordered_map<std::string, std::vector<Task>>
Todolist_model::get_tasks() const
{
  return tasks;
}
