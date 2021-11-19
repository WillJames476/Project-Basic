/*
 * todolist v1.6
 * by: William James Landicho
 * date started: November 4 2021
 * date last updated : November 18 2021
 * 
 * version 1.0:
 *      basic task_management (deletion and addition of task),
 *      file persistence implemented
 * version 1.5:
 *      accounts system added
 * version 1.6:
 *      months date checking added, now out of date tasks will
 *      be removed from the list
*/

/*
 * libraries used
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
#include <array>

/*
 * constants used on the program;
*/
const std::time_t current_time = std::time(0);
const std::tm *current_date = std::localtime(&current_time);
const std::array<int,12>months_ceiling{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
 * all classes relating to the account functionalities of the program
*/
class Accounts
{
    private:
        std::map<std::string, std::string> accounts;
    public:
        void new_account(const std::string& account_name, const std::string& account_password, const bool is_new);
        void make_new_file(const std::string& account_name);
        std::string account_login(const std::string& account_name, const std::string& account_password);
        void save_accounts_to_a_file(const std::string& accounts_file);
        void load_accounts_from_file(const std::string& accounts_file);
};

void Accounts::new_account(const std::string& account_name, const std::string &account_password, const bool is_new)
{
    accounts.emplace(std::make_pair(account_name, account_password));

    if(is_new)make_new_file(account_name);
}

std::string Accounts::account_login(const std::string& account_name, const std::string &account_password)
{
    std::map<std::string ,std::string>::iterator z = accounts.find(account_name);

    if(z!= accounts.end() && z->second == account_password) return "users/"+ z->second +".txt";
    return NULL;
}

void Accounts::make_new_file(const std::string& account_name)
{
    std::ofstream file_to_make("users/" + account_name + ".txt");
    file_to_make.close();
}

void Accounts::load_accounts_from_file(const std::string& accounts_file)
{
    std::ifstream file_to_read(accounts_file);
    std::string user_name_accumulator, password_accumulator;

    while(file_to_read >> user_name_accumulator >> password_accumulator)
    {
        new_account(user_name_accumulator, password_accumulator, false);
    }

    file_to_read.close();
}

void Accounts::save_accounts_to_a_file(const std::string& accounts_file)
{
    std::ofstream file_archiver(accounts_file);
    std::string string_to_give_to_file;

    for(auto z : accounts)
    {
        string_to_give_to_file += z.first + " " + z.second + "\n";
    }

    file_archiver << string_to_give_to_file;

    file_archiver.close();
}

/*
 * all classes relating to the task functionalities of the program
*/
class Task
{
    private:    
        std::string task_name;
        std::tm task_time_due;
    public:
        bool test_var(const std::string task_name, const std::tm &task_time_due);
        std::string get_task_name()const;
        std::string stringify_time_due();
        std::string get_time_integral();
        std::time_t get_task_time();
        Task(const std::string& task_name, const std::tm& task_time_due);
        void print_task();
        std::tm get_dates();
};

Task::Task(const std::string& task_name, const std::tm& task_time_due)
{
    this->task_name = task_name;
    this->task_time_due = task_time_due;
}

void Task::print_task()
{
    std::cout << "task name: " << task_name << "\t task due: " <<  std::put_time(&this->task_time_due, "%b, %d") << '\n';
}

bool Task::test_var(const std::string task_name, const std::tm &task_time_due)
{
    return this->task_name == task_name &&
    this->task_time_due.tm_mon == task_time_due.tm_mon &&
    this->task_time_due.tm_mday == task_time_due.tm_mday;
}

std::string Task::get_task_name() const
{
    return this->task_name;
}

std::string Task::get_time_integral()
{   
    std::stringstream tm_getter;
    tm_getter << this->task_time_due.tm_mon << " " << this->task_time_due.tm_mday;
    return tm_getter.str();
}

std::time_t Task::get_task_time()
{
    return std::mktime(&this->task_time_due);
}

std::tm Task::get_dates()
{
    return this->task_time_due;
}

class Task_list
{
    private:
        std::vector <Task>task_list;
    public:
        std::string replace_all_instance_of_space_on_string(char character_to_replace,char character_replacement, std::string string_modifiy);
        void add_task_to_task_list(const std::string& task_name,const std::tm &task_date_due);
        void print_task_list();
        void remove_task_from_task_list(const std::string&task_name, const std::tm& task_date);
        void remove_task_from_task_list(const std::string& task_name, int &status);
        void save_task_to_file(const std::string &file_to_save_at);
        void load_task_from_file(const std::string &file_to_load_at);
        void sort_by_date();
        void remove_oudated_tasks();
};

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
    sort_by_date();

    while(this->task_list.back().get_dates().tm_mon < current_date->tm_mon ||
    this->task_list.back().get_dates().tm_mon == current_date->tm_mon && 
    this->task_list.back().get_dates().tm_mday < current_date->tm_mday)
    {
        this->task_list.pop_back();
    }

    std::reverse(this->task_list.begin(), this->task_list.end());
}

/*
 * funtcion prototypes
*/
std::string extract_alpha_space_string_from_user(const std::string &request);
std::string extract_allpha_string_from_user(const std::string &request);
void get_a_date_from_user(std::tm& to_return);
int get_a_time_from_user(const std::string& request, int min_range, int max_range);
void add_task_incrementally(const std::string &task_name, std::tm time_start, Task_list &task_list, int day_increment);
void add_task_manager(Task_list &task_list);
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
    std::tm date_input;
    bool menu_replay = true;

    task_list.load_task_from_file(user_file);
    task_list.remove_oudated_tasks();

    while(menu_replay)
    {
        std::cout << "\n==========================================\n"
                  << "1\tadd item to task_list\n"
                  << "2\tdelete item from task_list\n"
                  << "3\tview all tasks\n"
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
                task_list.print_task_list();
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
        for(;time_start.tm_mday <= months_ceiling[time_start.tm_mon];time_start.tm_mday+= day_increment)
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

    task_name = extract_allpha_string_from_user("task name");

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

std::string extract_alpha_space_string_from_user(const std::string &request)
{
    std::string output;
    bool verified = false;

    while(!verified)
    {
        std::cout << "entert the " << request << " here: ";
        std::getline(std::cin, output);

        if(std::all_of(output.begin(), output.end(),
        [](char to_test){return isalpha(to_test) || isspace(to_test);})) verified = true;
    }

    return output;
}

std::string extract_allpha_string_from_user(const std::string &request)
{
    std::string output;
    bool verified = false;

    while(!verified)
    {
        std::cout << "enter the " << request << " here: ";
        std::getline(std::cin, output);

        if(std::all_of(output.begin(), output.end(),
        [](char to_test){return isalpha(to_test);})) verified = true;
    }

    return output;
}

void get_a_date_from_user(std::tm& to_return)
{
    to_return.tm_mon= get_a_time_from_user("month", current_date->tm_mon, 11);
    to_return.tm_mday = get_a_time_from_user("day", current_date->tm_mday, months_ceiling[current_date->tm_mon]);
}

int get_a_time_from_user(const std::string& request, int min_range, int max_range)
{
    std::string string_input;
    bool verified = false;

    while(!verified)
    {
        std::cout << "enter the " << request << " here("  <<  min_range << '-' << max_range << "): ";
        std::getline(std::cin, string_input);

        if(std::all_of(string_input.begin(), string_input.end(),
        [](char to_test){return isdigit(to_test);}))
        {
            if(std::stoi(string_input) >= min_range && std::stoi(string_input) <= max_range)verified = true;
        }  
    }
    return std::stoi(string_input);
} 
