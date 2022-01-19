#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <chrono>
#include <iostream>

class Task
{
    public:
        Task() = default;
        Task(const std::string& name, const std::tm& task_due);
        Task(const std::string& name,const std::string& giver, const std::tm& task_time_due);
        std::time_t get_task_time();
        std::tm get_dates() const;
        std::tuple<std::string, std::string, std::tm> get_specifications() const;
        void print_task();

        friend bool operator==(const Task& first, const Task& second);
        friend bool operator==(const Task& task,const std::string& to_compare);
        friend std::ostream& operator<<(std::ostream& out,Task& task);
        friend std::istream& operator>>(std::istream& in,Task& task);

	private:
		std::string task_name;
		std::string task_giver;
		std::tm task_time_due;
};

#endif
