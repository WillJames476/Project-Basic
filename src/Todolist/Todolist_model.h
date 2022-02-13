#ifndef TODOLIST_MODEL_H
#define TODOLIST_MODEL_H

#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

#include "Task.h"

class Todolist_model
{
    public:
        Todolist_model() = default;

        void add_to_list(const std::string& account_name);

        void add_to_list_task(const std::string& account_target
                            , const std::string& task_name
                            , const std::string& account_source);

        void remove_from_list(const std::string& account_name);

        void remove_from_list_task(const std::string& account_target
                            , const std::string& task_name
                            , const std::string& account_source);
        
        bool task_exists(const std::string& account_target
                            , const std::string& task_name
                            , const std::string& account_source);

        std::vector<Task> get_item_from_list(const std::string& account_name) const;
        std::unordered_map<std::string, std::vector<Task>> get_tasks() const;

    private:
        std::unordered_map<std::string, std::vector<Task>> tasks;
};

#endif