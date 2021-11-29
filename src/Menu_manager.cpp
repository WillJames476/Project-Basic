#include <iostream>
#include <sstream>

#include "Account/Users_list.h"
#include "Menu_manager.h"
#include "Utilities/io.h"
#include "Todolist/constants.h"

void user_account_management(std::string& account_name,
Users_list& users)
{
    bool menu_replay{true};

    while(menu_replay)
    {
        std::ostringstream menu;
        menu << "\n===============================\n"
            << "1\tadd a communication line\n"
            << "2\tchoose what user file to acces\n"
            << "3\texit account communications chooser\n"
            << "enter your choice here: ";
        std::cout << menu.str();
        std::string menu_choice;
        std::getline(std::cin, menu_choice);

        switch(menu_choice.at(0))
        {
            case '1':
                users.add_communication_line
                (extract_allpha_string_from_user("user to comunicate with"));
                break;
            case '2':
                users.print_communication_line(account_name);
                //account_name
                break;
            case '3':
                menu_replay = false;
                break;
        }
    }
}

std::string accounts_manager(const std::string& accounts_file)
{
    Users_list accounts;
    std::string menu_choice, chosen_user_file;
    std::vector<std::string> user_file;
    bool menu_replay = true;

    accounts.load_accounts_from_file(accounts_file);

    while(menu_replay)
    {
        std::cout << "\n=================================\n"
                  << "1\tadd a user\n"
                  << "2\tremove a user\n"
                  << "3\tuser login\n"
                  << "4\texit program\n"
                  << "enter your choice here: ";
        std::getline(std::cin, menu_choice);

        switch (menu_choice.at(0))
        {
            case '1':
                accounts.new_account
                (extract_allpha_string_from_user("user name"), 
                extract_allpha_string_from_user("password"), true);
                break;
            case '2':
                accounts.remove_account
                (extract_allpha_string_from_user("user name"), 
                extract_allpha_string_from_user("password"));
                break;
            case '3':
                user_file = accounts.account_login(extract_allpha_string_from_user("user name"), extract_allpha_string_from_user("password"));
                break;
            case '4':
                menu_replay = false;
                break;
            default:
                break;
        }
    }
    accounts.save_accounts_to_a_file(accounts_file);
    user_account_management(chosen_user_file, accounts);
    return chosen_user_file;
}

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
        else time_start.tm_mday = RESETTER; //resets day for next month
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