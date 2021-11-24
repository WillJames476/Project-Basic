/*
 * todolist v1.6
 * by: William James Landicho
 * date started: November 4 2021
 * date last updated : November 24 2021
 * 
 * version 1.0:
 *      basic task_management (deletion and addition of task),
 *      file persistence implemented
 * version 1.5:
 *      accounts system added
 * version 1.6:
 *      months date checking added, now out of date tasks will
 *      be removed from the list, bug fixed where when making new account
 *      two files are created when it is inteded to be only one
 *      added a feature where tou can only view tasks that is only on the
 *      current date
*/

/*
 * libraries used
*/
#include <iostream>
#include <string>
#include <sstream>

#include "constants.h"
#include "accounts.h"
#include "task_list.h"
#include "io.h"

/*
 * funtcion prototypes
*/
void add_task_incrementally(const std::string &task_name, std::tm time_start, Task_list &task_list, int day_increment);
void add_task_manager(Task_list &task_list);
void print_task_menu(Task_list& task_list);
void remove_task_manager(Task_list& task_list);
void task_manager(const std::string& user_file);
std::string accounts_manager(const std::string& accounts_file);

int main()
{
    std::string file_of_the_user;
    file_of_the_user = accounts_manager("users/users.txt");

    if(!file_of_the_user.empty())
    {
        task_manager(file_of_the_user);
    }

    return 0;
}

std::string accounts_manager(const std::string& accounts_file)
{
    Accounts accounts;
    std::string menu_choice, user_file;
    bool menu_replay = true;

    accounts.load_accounts_from_file(accounts_file);

    while(menu_replay)
    {
        std::cout << "\n=================================\n"
                  << "1\tadd a user\n"
                  << "2\tuser login\n"
                  << "3\texit program\n"
                  << "enter your choice here: ";
        std::getline(std::cin, menu_choice);

        switch (menu_choice.at(0))
        {
            case '1':
                accounts.new_account(extract_allpha_string_from_user("user name"), extract_allpha_string_from_user("password"), true);
                break;
            case '2':
                user_file = accounts.account_login(extract_allpha_string_from_user("user name"), extract_allpha_string_from_user("password"));
                break;
            case '3':
                menu_replay = false;
                break;
            default:
                break;
        }
    }
    accounts.save_accounts_to_a_file(accounts_file);

    return user_file;
}

void task_manager(const std::string& user_file)
{
    Task_list task_list;
    std::string menu_choice;
    bool menu_replay = true;

    task_list.load_task_from_file(user_file);
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

    task_list.save_task_to_file(user_file);
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
            add_task_incrementally(task_name, task_due, task_list, 1);
            break;
        case '3':
            add_task_incrementally(task_name, task_due, task_list, 7);
            break;
        case '4':
            add_task_incrementally(task_name, task_due, task_list, 31);
            break;
        default:
            std::cerr << "Invalid entry!!!\n";
            break;
    }
}

void add_task_incrementally(const std::string &task_name, std::tm time_start, Task_list &task_list, int day_increment)
{
    const int RESETTER = time_start.tm_mday;
    for(;time_start.tm_mon <= 11; time_start.tm_mon++)
    {
        for(;time_start.tm_mday <= constants::months_ceiling[time_start.tm_mon];time_start.tm_mday+= day_increment)
        {
            task_list.add_task_to_task_list(task_name, time_start);
        }
        time_start.tm_mday = RESETTER; //resets day for next month
    }
}

void remove_task_manager(Task_list& task_list)
{
    std::string menu_choice, task_name;
    std::tm task_due;
    int deletion_status = 0;

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
            while(deletion_status != -1)task_list.remove_task_from_task_list(task_name, deletion_status);
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