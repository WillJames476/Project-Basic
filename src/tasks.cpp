#include "tasks.h"
#include <iostream>
#include <iomanip>

Task::Task(const std::string& task_name, const std::tm& task_time_due)
{
    this->task_name = task_name;
    this->task_time_due = task_time_due;
}

void Task::print_task()
{
    std::cout << "task name: " << task_name << "\t task due: " <<  std::put_time(&this->task_time_due, "%b, %d") << '\n';
}

bool Task::test_var(const std::string task_name, const std::tm &task_time_due)
{
    return this->task_name == task_name &&
    this->task_time_due.tm_mon == task_time_due.tm_mon &&
    this->task_time_due.tm_mday == task_time_due.tm_mday;
}

std::string Task::get_task_name() 
{
    return this->task_name;
}

std::string Task::get_time_integral()
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