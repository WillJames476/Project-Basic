#include "tasks.h"
#include <iostream>
#include <iomanip>
#include <sstream>

#include "../Utilities/io.h"

Task::Task()
{

}

Task::Task(const std::string& task_name, const std::tm& task_time_due)
{
    this->task_name = task_name;
    this->task_time_due = task_time_due;
}

void Task::print_task()
{
    std::ostringstream to_print;
    to_print << "task name: " << task_name 
    << "\t task due: " <<  std::put_time(&this->task_time_due, "%b, %d") << '\n';
    std::cout << to_print.str();
}

bool Task::test_var(const std::string task_name, const std::tm &task_time_due)
{
    return this->task_name == task_name &&
    this->task_time_due.tm_mon == task_time_due.tm_mon &&
    this->task_time_due.tm_mday == task_time_due.tm_mday;
}

std::string Task::get_task_name() const
{
    return this->task_name;
}

std::string Task::get_time_integral() const
{   
    std::stringstream tm_getter;
    tm_getter << this->task_time_due.tm_mon << " " << this->task_time_due.tm_mday;
    return tm_getter.str();
}

std::time_t Task::get_task_time()
{
    return std::mktime(&this->task_time_due);
}

std::tm Task::get_dates()
{
    return this->task_time_due;
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