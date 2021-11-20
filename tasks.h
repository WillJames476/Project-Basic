#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <ctime>

class Task
{
    private:    
        std::string task_name;
        std::tm task_time_due;
    public:
        bool test_var(const std::string task_name, const std::tm &task_time_due);
        std::string get_task_name()const;
        std::string stringify_time_due();
        std::string get_time_integral();
        std::time_t get_task_time();
        Task(const std::string& task_name, const std::tm& task_time_due);
        void print_task();
        std::tm get_dates();
};

#endif