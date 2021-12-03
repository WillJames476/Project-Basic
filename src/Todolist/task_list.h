#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "tasks.h"
#include <vector>
#include <string>

#include "../Utilities/List_management.h"

class Task_list : public List_management
{
    private:
        std::vector <Task>task_list;
    public:
        bool is_existing(const std::string& task_name);
        void add_to_list(const std::initializer_list<std::string>& fields);
        void add_task_to_task_list(const Task& task);
        void print_task_list();
        void remove_from_list(const std::initializer_list<std::string>& fields);
        void remove_all_from_list(const std::string& task_name);
        void save_to_file(const std::string &file_to_save_at);
        void load_from_file(const std::string &file_to_load_at);
        void sort_by_date();
        void remove_oudated_tasks();
        void print_task_for_this_day();
};

#endif