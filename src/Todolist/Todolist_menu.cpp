#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>

#include "Todolist_menu.h"
#include "task_list.h"
#include "constants.h"
#include "../includes/io.h"
#include "../includes/extras.h"

void add_task_incrementally(const std::string &task_name
                            , std::tm time_start
                            , Task_list &task_list
                            , int day_increment
                            , bool is_daily
                            , const std::string& task_giver)
{
    if(day_increment != 0)
    {
        const int RESETTER = time_start.tm_mday;
        for(;time_start.tm_mon <= 11; time_start.tm_mon++)
        {
            for(;time_start.tm_mday <= constants::months_ceiling[time_start.tm_mon];time_start.tm_mday+= day_increment)
            {
                task_list.add_to_list(Task{task_name, task_giver, time_start});
            }

            if(is_daily) time_start.tm_mday = 1;
            else time_start.tm_mday = RESETTER;
        }
    }
    else
    {
        task_list.add_to_list(Task{task_name, task_giver, time_start});
    }
}

void task_manager_clintrl(Task_list& tasks 
                        , const std::string& accessor
                        , const boost::program_options::options_description& options
                        , const boost::program_options::variables_map& vm)
{
    using namespace REGEX_PREDICATES;

    if(vm.count("help"))
    {
        std::cout << options;
    }
    if(vm.count("view"))
    {
        tasks.print_list();
    }
    if(vm.count("delete"))
    {
        apply_function<Task_list>(vm["delete"].as<std::vector<std::string>>()
            ,1, "--delete", {ALPHA}, [&](const auto& fields)
                {tasks.remove_all_from_list(fields[0]);});
    }
    if(vm.count("deletesp"))
    {
        apply_function<Task_list>(vm["deletesp"].as<std::vector<std::string>>(),
            3, "--deletesp", {ALPHA, MONTH, DATE}, [&](const auto& fields)
                {
                    std::tm date_specified;
                    date_specified.tm_mon = std::stoi(fields[1]);
                    date_specified.tm_mday = std::stoi(fields[2]);

                    tasks.remove_from_list(Task{fields[0], date_specified});
                });
    }
    if(vm.count("add"))
    {
        apply_function<Task_list>(vm["add"].as<std::vector<std::string>>(),
            4, "--add", {ALPHA, MONTH, DATE, DATE}, [&](const auto& fields)
                {
                    const int INCREMENT = std::stoi(fields[3]);
                    bool is_daily = std::stoi(fields[3]) == 1 ? true : false;
                    std::tm start_date;
                    start_date.tm_mon  = std::stoi(fields[1]);
                    start_date.tm_mday = std::stoi(fields[2]);
                    
                    add_task_incrementally (fields[0], start_date, tasks
                        , INCREMENT, is_daily, accessor);
                });
    }
}

void task_manager_cli(int argc
                    , char** argv
                    ,const std::array<std::string,2>& acces_descriptor)
{
    using namespace boost::program_options;

    Task_list task_list   {};
    std::string file_name {"users/" + acces_descriptor[0] 
        + "/" + acces_descriptor[0] + "_tasks.txt"};

    load_from_file<Task_list>(file_name, task_list);
    task_list.remove_oudated_tasks();

    try
    {
        options_description options {"options"};
        options.add_options()
        ("help", "show the available commands")
        ("add", value<std::vector<std::string>>()->multitoken()->composing()->zero_tokens(),
            "adds a task to the task list")
        ("delete", value<std::vector<std::string>>()->multitoken()->composing()->zero_tokens(),
            "removes all task from the task list")
        ("deletesp", value<std::vector<std::string>>()->multitoken()->composing()->zero_tokens(),
            "deletes a specified task")
        ("view", "view all the tasks");

        variables_map vm;
        store(parse_command_line(argc, argv, options), vm);
        notify(vm);
        task_manager_clintrl(task_list, acces_descriptor[1],options, vm);
    }
    catch(const error &excpt)
    {
        std::cerr << excpt.what() << '\n';
    }

    save_to_file<Task_list>(file_name, task_list);
}

