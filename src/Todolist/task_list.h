#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "tasks.h"
#include <vector>
#include <string>

class Task_list
{
    public:
        void add_to_list(const std::string& task_name, const std::tm& task_time, 
        const std::string& task_giver);
        void remove_from_list(const std::initializer_list<std::string>& fields);
        void remove_all_from_list(const std::string& task_name);
        void sort_by_date();
        void remove_oudated_tasks();
        void print_task_for_this_day();

        friend std::ostream& operator<<(std::ostream& out,const Task_list& tasks);
        friend std::istream& operator>>(std::istream& in, Task_list& tasks);

	private:
		std::vector<Task> task_list;
};

#endif
