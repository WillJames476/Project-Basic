#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "tasks.h"
#include <vector>
#include <string>

class Task_list
{
    private:
        std::vector <Task>task_list;
    public:
        std::string replace_all_instance_of_space_on_string(char character_to_replace,char character_replacement, std::string string_modifiy);
        void add_task_to_task_list(const std::string& task_name,const std::tm &task_date_due);
        void print_task_list();
        void remove_task_from_task_list(const std::string&task_name, const std::tm& task_date);
        void remove_task_from_task_list(const std::string& task_name, int &status);
        void save_task_to_file(const std::string &file_to_save_at);
        void load_task_from_file(const std::string &file_to_load_at);
        void sort_by_date();
        void remove_oudated_tasks();
};

#endif