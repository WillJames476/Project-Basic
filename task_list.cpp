#include "task_list.h"
#include "constants.h"
#include <algorithm>
#include <fstream>

void Task_list::add_task_to_task_list(const std::string& task_name, const std::tm &task_date_due)
{
    task_list.push_back(Task(task_name, task_date_due));
}

void Task_list::remove_task_from_task_list(const std::string& task_name, const std::tm& task_date)
{
    auto i = task_list.end();

    for(std::vector<Task>::iterator z = task_list.begin(); z != task_list.end();z++)
    {
        if(z->test_var(task_name, task_date))
        {
            i = z;
            break;
        }
    }

    if(i != task_list.end())this->task_list.erase(i);
}

void Task_list::remove_task_from_task_list(const std::string& task_name_to_remove, int &status)
{
    auto i = task_list.end();

    for(std::vector<Task>::iterator z = task_list.begin(); z != task_list.end();z++)
    {
        if(z->get_task_name() == task_name_to_remove)
        {
            i = z;
            break;
        }
    }

    if(i != task_list.end())
    {
        this->task_list.erase(i);
        return;
    }
    status = -1;
}

void Task_list::print_task_list()
{
    std::for_each(task_list.begin(), task_list.end(),[](Task task){task.print_task();});
}
std::string Task_list::replace_all_instance_of_space_on_string(char character_to_replace, char character_replacement, std::string string_modifiy)
{
    std::replace_if(string_modifiy.begin(), string_modifiy.end(),
    [character_replacement, character_to_replace](char to_test)
    {return to_test == character_to_replace;},character_replacement);

    return string_modifiy;
}

void Task_list::load_task_from_file(const std::string& file_to_load_at)
{
    std::ifstream archived_file(file_to_load_at);
    std::string file_contents_accumulator, task_name_accumulator;
    std::tm date_accumulator;

    while(archived_file >> task_name_accumulator >> date_accumulator.tm_mon >> date_accumulator.tm_mday)
    {
        add_task_to_task_list(replace_all_instance_of_space_on_string('-',' ',task_name_accumulator), date_accumulator);
    }

    archived_file.close();
}

void Task_list::save_task_to_file(const std::string& file_to_save_at)
{
    std::ofstream archive_here(file_to_save_at);
    std::string string_saver;

    for(auto i :task_list)string_saver += replace_all_instance_of_space_on_string(' ','-', i.get_task_name()) + " " + i.get_time_integral() + '\n';
    archive_here << string_saver;

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
    if(!this->task_list.empty())
    {
        sort_by_date();

        while(this->task_list.back().get_dates().tm_mon < constants::current_date->tm_mon ||
        this->task_list.back().get_dates().tm_mon == constants::current_date->tm_mon && 
        this->task_list.back().get_dates().tm_mday < constants::current_date->tm_mday)
        {
            this->task_list.pop_back();
        }

        std::reverse(this->task_list.begin(), this->task_list.end());
    }
}