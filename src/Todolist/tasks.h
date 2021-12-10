#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <chrono>
#include <iostream>

class Task
{
    private:    
        std::string task_name;
        std::tm task_time_due;
    public:
        Task();
        Task(const std::string& task_name, const std::tm& task_time_due);
        std::time_t get_task_time();
        std::tm get_dates() const;
        
        friend bool operator==(const Task& first, const Task& second);
        friend bool operator==(const Task& task,const std::string& to_compare);
        friend std::ostream& operator<<(std::ostream& out,Task& task);
        friend std::istream& operator>>(std::istream& in,Task& task);
};

#endif