#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <ctime>
#include <iostream>

class Task
{
    private:    
        std::string task_name;
        std::tm task_time_due;
    public:
        Task();
        bool test_var(const std::string task_name, const std::tm &task_time_due);
        std::string get_task_name() const;
        std::string stringify_time_due() const;
        std::string get_time_integral() const;
        std::time_t get_task_time();
        Task(const std::string& task_name, const std::tm& task_time_due);
        void print_task();
        std::tm get_dates();
        
        friend bool operator==(const Task& task,const std::string& to_compare);
        friend std::ostream& operator<<(std::ostream& out,Task& task);
        friend std::istream& operator>>(std::istream& in,Task& task);
};

#endif