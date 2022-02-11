#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
    public:
        Task(const std::string& task_name
            , const std::string& task_giver);

        std::string get_task_name() const;
        std::string get_task_giver() const;

    private:
        std::string task_name_str;
        std::string task_giver_str;
};

#endif