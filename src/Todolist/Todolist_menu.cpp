#include <iostream>
#include <fstream>

#include "Todolist_menu.h"
#include "task_list.h"
#include "constants.h"
#include "../Utilities/io.h"

void load_from_file(const std::string& file_name, Task_list& tasks)
{
    try
    {
        std::fstream file_to_read("users/" + file_name + "/" + file_name + "_tasks.txt", 
        std::ios_base::in);
        file_to_read >> tasks;
        file_to_read.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void save_to_file(const std::string& file_name, const Task_list& tasks)
{
    try
    {
        std::fstream file_to_read("users/" + file_name + "/" + file_name + "_tasks.txt", 
        std::ios_base::out);
        file_to_read << tasks;
        file_to_read.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void add_task_incrementally(const std::string &task_name, 
std::tm time_start, Task_list &task_list, int day_increment,
bool is_daily, const std::string& task_giver)
{
    const int RESETTER = time_start.tm_mday;
    for(;time_start.tm_mon <= 11; time_start.tm_mon++)
    {
        for(;time_start.tm_mday <= constants::months_ceiling[time_start.tm_mon];time_start.tm_mday+= day_increment)
        {
            task_list.add_to_list(task_name, time_start, task_giver);
        }

        if(is_daily) time_start.tm_mday = 1;
        else time_start.tm_mday = RESETTER;
    }
}

char add_task_menu()
{
    std::ostringstream menu;
    menu << "1\tone time occurence\n"
        << "2\tdaily\n"
        << "3\tweekly\n"
        << "4\tmonthly\n"
        << "enter your choice here: ";
    return get_integral<char>(menu.str(), '0' ,'5');
}

void add_task_control_flow(Task_list& task_list, char menu_choice,
const std::string& task_giver)
{
    std::string task_name{get_string("enter the task name here: ", 
    string_predicates("AlphaSpace"))};
    std::tm task_due;
    get_a_date_from_user(task_due);

    switch (menu_choice)
    {
        case '1':
            task_list.add_to_list(task_name, task_due, task_giver);
            break;
        case '2':
            add_task_incrementally(task_name, task_due, task_list, 
            1 ,true, task_giver);
            break;
        case '3':
            add_task_incrementally(task_name, task_due, task_list, 
            7, false, task_giver);
            break;
        case '4':
            add_task_incrementally(task_name, task_due, task_list, 
            31, false, task_giver);
            break;
    }
}

void add_task(Task_list &task_list,const std::string& accessor)
{
    add_task_control_flow(task_list, add_task_menu(), accessor);
}

char remove_task_menu()
{
    std::ostringstream menu;
    menu << "1\tan instance of task_name\n"
        << "2\tall instance of task name\n"
        << "enter your choice here: ";
    return get_integral<char>(menu.str(), '0', '3');
}

void remove_task_control_flow(Task_list& task_list, char menu_choice)
{
    std::tm task_due;
    std::string task_name{get_string("enter the task name here: ",
    string_predicates("AlphaSpace"))};

    switch (menu_choice)
    {
        case '1':
            get_a_date_from_user(task_due);
            task_list.remove_from_list({task_name, std::to_string(task_due.tm_mon),
            std::to_string(task_due.tm_mday)});
            break;
        case '2':
            task_list.remove_all_from_list(task_name);
            break;
    }
}

void remove_task(Task_list& task_list)
{
    remove_task_control_flow(task_list, remove_task_menu());
}

char print_task_menu()
{
    std::ostringstream menu;
    menu << "1\tview tasks for this day\n"
        << "2\tview all tasks\n"
        << "enter you choice here: ";
    return get_integral<char>(menu.str(), '0', '3');
}

void print_task_control_flow(Task_list& task_list, char menu_choice)
{
    switch(menu_choice)
    {
        case '1':
            task_list.print_task_for_this_day();
            break;
        case '2':
            std::cout << task_list;
            break;
    }
}

void print_task(Task_list& task_list)
{
    print_task_control_flow(task_list, print_task_menu());
}

char task_manager_menu()
{
    std::ostringstream menu;
    menu << "\n==========================================\n"
        << "1\tadd item to tasklist\n"
        << "2\tdelete item from task_list\n"
        << "3\tview task list\n"
        << "4\texit the program\n"
        << "enter your chocie here: ";
    return get_integral<char>(menu.str(), '0', '5');
}

void task_manager_control_flow(Task_list& task_list,
char menu_choice, bool& menu_replay, const std::string& accessor)
{
    switch(menu_choice)
    {
        case '1':
            add_task(task_list, accessor);
            break;
        case '2':
            remove_task(task_list);
            break;
        case '3':
            print_task(task_list);
            break;
        case '4':
            menu_replay = false;
            break;
    }
}

void task_manager(const std::array<std::string,2>& access_descriptor)
{
    Task_list task_list{};
    bool menu_replay{true};

    load_from_file(access_descriptor[0], task_list);
    task_list.remove_oudated_tasks();

    while(menu_replay)
    {
       task_manager_control_flow(task_list, task_manager_menu(),
       menu_replay, access_descriptor[1]);
    }
    save_to_file(access_descriptor[0], task_list);
}
