#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "task_list.h"
#include "constants.h"
#include "../includes/io.h"
#include "tasks.h"

void Task_list::add_item(const Task& to_add)
{
    task_list.push_back(to_add);
}

void Task_list::remove_item(const Task& to_remove)
{
    task_list.erase(std::remove(task_list.begin(), task_list.end(), to_remove));
}

void Task_list::print_items()
{
    std::cout << "task name\ttask giver\ttime to acomplish\n";

    for(auto&x : task_list)
    {
        x.print_task();
    }
}

void Task_list::remove_all_from_list(const std::string& task_name)
{
    while(std::any_of(task_list.begin(), task_list.end(),
    [&](auto task){return task == task_name;}))
    {
        task_list.erase(std::remove(task_list.begin(), task_list.end(), task_name));
    }
}

void Task_list::sort_by_date()
{
    std::sort(this->task_list.begin(), this->task_list.end(),
    [](Task& z,Task& f)
    {return z.get_task_time() > f.get_task_time();});
}

void Task_list::remove_oudated_tasks()
{
    if(!task_list.empty())
    {
        auto test = constants::current_date;

        task_list.erase(std::remove_if(this->task_list.begin()
            , this->task_list.end(),
                [&](const auto& z)
                {return (z.get_dates().tm_mon > test->tm_mon) 
                    || (z.get_dates().tm_mon == test->tm_mon 
                        && z.get_dates().tm_mday > test->tm_mday)
                    ;}));
    }
}

void Task_list::print_task_for_this_day()
{
    auto temp = constants::current_date;
    std::array<const std::tm*, 1>test{temp};

    std::for_each(this->task_list.begin(), 
        std::find_first_of(this->task_list.begin(), this->task_list.end()
        ,test.begin(),test.end(),
        [](const auto& z,const auto& x)
            {return x->tm_mday != z.get_dates().tm_mday;})
            ,[](auto f)
                {f.print_task();});
}

std::ostream& operator<<(std::ostream& out
                    , const Task_list& tasks)
{
   for(auto x : tasks.task_list) out << x;
   return out;
}

std::istream& operator>>(std::istream& in
                    , Task_list& tasks)
{
    Task temp{};
    while(in >> temp)tasks.task_list.push_back(temp);
    return in;
}