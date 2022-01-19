#include "tasks.h"
#include <iostream>
#include <iomanip>
#include <sstream>

#include "../includes/io.h"

Task::Task(const std::string& name_given, const std::tm& due_given)
: task_name{name_given},task_giver{}, task_time_due{due_given}
{
}

Task::Task(const std::string& name_given,const std::string& giver,
const std::tm& due_given)
: task_name{name_given},task_giver{giver}, task_time_due{due_given}
{
}

std::tuple<std::string, std::string, std::tm> Task::get_specifications() const
{
    return{task_name, task_giver, task_time_due};
}

std::time_t Task::get_task_time() 
{
    return std::mktime(&this->task_time_due);
}

std::tm Task::get_dates() const
{
    return this->task_time_due;
}

void Task::print_task()
{
    std::ostringstream output;

    output << task_name << '|' 
    << "\t" << task_giver << '|' 
    << std::put_time(&task_time_due, "\t%B %d\n");

    std::cout << output.str();
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
    out << task.task_name << " " << task.task_time_due.tm_mon 
    << " " << task.task_time_due.tm_mday << " " << task.task_giver<< '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Task& task)
{
    in >> task.task_name >> task.task_time_due.tm_mon 
    >> task.task_time_due.tm_mday >> task.task_giver;
    return in;
}