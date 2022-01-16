#ifndef TASK_LIST_H
#define TASK_LIST_H

#include <vector>
#include <string>
#include "tasks.h"
#include "../includes/List_crtp.h"

class Task_list : public List_crtp<Task_list, Task>
{
    public:
        void add_item(const Task& to_add);
        void remove_item(const Task& to_remove);
        void remove_all_from_list(const std::string& task_name);
        void sort_by_date();
        void remove_oudated_tasks();
        void print_items();
        void print_task_for_this_day();

        friend std::ostream& operator<<(std::ostream& out,const Task_list& tasks);
        friend std::istream& operator>>(std::istream& in, Task_list& tasks);

	private:
		std::vector<Task> task_list;
};

#endif
