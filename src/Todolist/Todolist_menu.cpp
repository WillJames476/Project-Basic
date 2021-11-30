#include <string>
#include <iostream>
#include "Todolist_menu.h"
#include "task_list.h"
#include "constants.h"
#include "../Utilities/io.h"

void add_task_incrementally(const std::string &task_name, 
std::tm time_start, Task_list &task_list, int day_increment,
bool is_daily)
{
    const int RESETTER = time_start.tm_mday;
    for(;time_start.tm_mon <= 11; time_start.tm_mon++)
    {
        for(;time_start.tm_mday <= constants::months_ceiling[time_start.tm_mon];time_start.tm_mday+= day_increment)
        {
            task_list.add_task_to_task_list(task_name, time_start);
        }

        if(is_daily) time_start.tm_mday = 1;
        else time_start.tm_mday = RESETTER;
    }
}

void add_task_manager(Task_list &task_list)
{
    std::string menu_choice, task_name;
    std::tm task_due;

    std::cout << "1\tone time occurence\n"
              << "2\tdaily\n"
              << "3\tweekly\n"
              << "4\tmonthly\n"
              << "enter your choice here: ";
    std::getline(std::cin, menu_choice);

    task_name = extract_alpha_space_string_from_user("task name");
    get_a_date_from_user(task_due);

    switch (menu_choice.at(0))
    {
        case '1':
            task_list.add_task_to_task_list(task_name, task_due);
            break;
        case '2':
            add_task_incrementally(task_name, task_due, task_list, 
            1 ,true);
            break;
        case '3':
            add_task_incrementally(task_name, task_due, task_list, 
            7, false);
            break;
        case '4':
            add_task_incrementally(task_name, task_due, task_list, 
            31, false);
            break;
        default:
            std::cerr << "Invalid entry!!!\n";
            break;
    }
}

void remove_task_manager(Task_list& task_list)
{
    std::string menu_choice, task_name;
    std::tm task_due;
    std::cout << "1\tan instance of task_name\n"
              << "2\tall instance of task name\n"
              << "enter your choice here: ";
    std::getline(std::cin, menu_choice);

    task_name = extract_alpha_space_string_from_user("task name");

    switch (menu_choice.at(0))
    {
        case '1':
            get_a_date_from_user(task_due);
            task_list.remove_task_from_task_list(task_name, task_due);
            break;
        case '2':
            while(task_list.is_existing(task_name))
            task_list.remove_task_from_task_list(task_name);
            break;
        default:
            std::cerr << "Invalid entry!!!\n";
            break;
    }
}

void print_task_menu(Task_list& task_list)
{
    std::string menu_choice;

    std::cout << "1\tview tasks for this day\n"
              << "2\tview all tasks\n"
              << "enter you choice here: ";
    std::getline(std::cin, menu_choice);

    switch(menu_choice.at(0))
    {
        case '1':
            task_list.print_task_for_this_day();
            break;
        case '2':
            task_list.print_task_list();
            break;
        default:
            std::cerr << "invalid entry\n";
            break;
    }
}

void task_manager(const std::string& user_file)
{
    Task_list task_list;
    std::string menu_choice;
    bool menu_replay = true;

    task_list.load_from_file(user_file);
    task_list.remove_oudated_tasks();

    while(menu_replay)
    {
        std::cout << "\n==========================================\n"
                  << "1\tadd item to tasklist\n"
                  << "2\tdelete item from task_list\n"
                  << "3\tview task list\n"
                  << "4\texit the program\n"
                  << "enter your chocie here: ";
        std::getline(std::cin, menu_choice);
        
        switch(menu_choice.at(0))
        {
            case '1':
                add_task_manager(task_list);
                break;
            case '2':
                remove_task_manager(task_list);
                break;
            case '3':
                print_task_menu(task_list);
                break;
            case '4':
                menu_replay = false;
                break;
            default:
                std::cerr << "Invalid entry\n";
                break;
        }
    }

    task_list.save_to_file(user_file);
}