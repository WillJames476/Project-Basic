#ifndef TASK_H
#define TASK_H

#include <string>

struct Task
{
    Task(const std::string& task_name,
	 const std::string& task_giver);
        
    std::string task_name_str;
    std::string task_giver_str;
};

#endif
