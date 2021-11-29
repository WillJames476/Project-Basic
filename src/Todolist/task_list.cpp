#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "task_list.h"
#include "constants.h"
#include "../io.h"

void Task_list::add_task_to_task_list(const std::string& task_name, const std::tm &task_date_due)
{
    task_list.push_back(Task(task_name, task_date_due));
}

void Task_list::remove_task_from_task_list(const std::string& task_name, const std::tm& task_date)
{
    task_list.erase(std::remove_if(task_list.begin(), task_list.end(),
    [task_name, task_date](auto test)
    {return test.test_var(task_name, task_date);}));
}
void Task_list::remove_task_from_task_list(const std::string& task_name)
{
    task_list.erase(std::remove_if(task_list.begin(), task_list.end(),
    [task_name](auto test)
    {return test.get_task_name() == task_name;}));
}

void Task_list::print_task_list()
{
    std::for_each(this->task_list.begin(), this->task_list.end(),
    [](Task task){task.print_task();});
}


void Task_list::load_task_from_file(const std::string& file_to_load_at)
{
    std::ifstream archived_file(file_to_load_at);
    std::string file_contents_accumulator, task_name_accumulator, 
    line_accumulator;
    std::tm date_accumulator;

    while(archived_file >> line_accumulator)
    {
        replace_char_with(line_accumulator, ',', ' ');
        std::istringstream(line_accumulator) >> task_name_accumulator
        >> date_accumulator.tm_mon >> date_accumulator.tm_mday;

        replace_char_with(task_name_accumulator, '-',' ');
        add_task_to_task_list(task_name_accumulator, date_accumulator);
    }

    archived_file.close();
}

void Task_list::save_task_to_file(const std::string& file_to_save_at)
{
    std::ofstream archive_here(file_to_save_at);
    std::ostringstream string_saver;

    for(auto i : this->task_list)
    {
        auto x {i.get_task_name()}, y{i.get_time_integral()};
        replace_char_with(x, ' ','-');
        replace_char_with(y, ' ',',');

        string_saver << x
        << "," << y << '\n';
    }
    archive_here << string_saver.str();
    archive_here.close();
}

void Task_list::sort_by_date()
{
    std::sort(this->task_list.begin(), this->task_list.end(),
    [](Task z, Task f)
    {return z.get_task_time() > f.get_task_time();});
}

void Task_list::remove_oudated_tasks()
{
    if(!task_list.empty())
    {
        auto test = constants::current_date;

        task_list.erase(std::remove_if(this->task_list.begin(), this->task_list.end(),
        [test](auto z)
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
        [](auto z, auto x)
        {return x->tm_mday != z.get_dates().tm_mday;})
    ,[](auto f)
    {f.print_task();});
}

bool Task_list::is_existing(const std::string& task_name)
{
    return std::any_of(this->task_list.begin(), this->task_list.end(),
    [task_name](auto x)
    {return x.get_task_name() == task_name;});
}