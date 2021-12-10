#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "task_list.h"
#include "constants.h"
#include "../Utilities/io.h"
#include "tasks.h"

void Task_list::add_to_list(const std::initializer_list<std::string>& fields)
{
    std::tm temp;
    std::vector<std::string> datas;
    for(const auto& x : fields)datas.push_back(x);

    temp.tm_mon = std::stoi(datas[1]);
    temp.tm_mday = std::stoi(datas[2]);
    task_list.push_back(Task(datas[0], temp));
}

void Task_list::remove_from_list(const std::initializer_list<std::string>& fields)
{
    std::tm temp;
    std::vector<std::string> datas;
    for(const auto& x : fields)datas.push_back(x);

    temp.tm_mon = std::stoi(datas[1]);
    temp.tm_mday = std::stoi(datas[2]);

    Task tmp{datas[0], temp};

    task_list.erase(std::remove(task_list.begin(), task_list.end(), tmp));
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

        task_list.erase(std::remove_if(this->task_list.begin(), this->task_list.end(),
        [&](const auto& z)
        {return (z.get_dates().tm_mon < test->tm_mon) ||
            (z.get_dates().tm_mon == test->tm_mon && 
            z.get_dates().tm_mday < test->tm_mday);}));
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
    {std::cout << f;});
}

std::ostream& operator<<(std::ostream& out, const Task_list& tasks)
{
   for(auto x : tasks.task_list) out << x;
   return out;
}

std::istream& operator>>(std::istream& in, Task_list& tasks)
{
    Task temp{};
    while(in >> temp)tasks.task_list.push_back(temp);
    return in;
}