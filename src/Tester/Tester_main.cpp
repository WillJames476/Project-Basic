#include <array>
#include <string>
#include <iostream>
#include <memory>

#include "../Todolist/Task.h"

int main()
{
    Task task{"make some bread", "slim"};

    std::cout << task.get_task_name() << " " << task.get_task_giver() << '\n';
    return 0;
}