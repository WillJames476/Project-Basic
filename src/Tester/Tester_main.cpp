#include <array>
#include <string>
#include <iostream>
#include <memory>

#include "../Todolist/Task.h"

int main()
{
    Task task{"make some bread", "slim"};

    std::cout << task.task_name_str << " " << task.task_giver_str << '\n';
    return 0;
}