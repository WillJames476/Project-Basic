#include "tasks.h"
#include <iostream>
#include <iomanip>
#include <sstream>

#include "../Utilities/io.h"

Task::Task()
{

}

Task::Task(const std::string& name_given, const std::tm& due_given)
: task_name{name_given}, task_time_due{due_given}
{
}

std::time_t Task::get_task_time() 
{
    return std::mktime(&this->task_time_due);
}

std::tm Task::get_dates() const
{
    return this->task_time_due;
}

bool operator==(const Task& first, const Task& second)
{
    return first.task_name == second.task_name &&
    first.task_time_due.tm_mon == second.task_time_due.tm_mon &&
    first.task_time_due.tm_mday == second.task_time_due.tm_mday;  
}

bool operator==(const Task& task,const std::string& to_compare)
{
    return task.task_name == to_compare;
}

std::ostream& operator<<(std::ostream& out,Task& task)
{
    out << task.task_name << " " << task.task_time_due.tm_mon << " " << task.task_time_due.tm_mday << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Task& task)
{
    in >> task.task_name >> task.task_time_due.tm_mon >> task.task_time_due.tm_mday;
    return in;
}