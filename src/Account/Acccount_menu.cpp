#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <boost/program_options.hpp>
#include <regex>

#include "Users_list.h"
#include "Account_menu.h"
#include "../Utilities/io.h"

bool entry_predicates(const std::vector<std::string>& list)
{
    using namespace REGEX_PREDICATES;

    for(const auto& datas : list)
    {
        if(!std::regex_match(datas, ALPHA_NOSPACE))
        {
            std::cerr << FEEDBACK_COLORS::BAD 
                    << "input is invalid\n"
                    << FEEDBACK_COLORS::RESET;
            return false;
        }
    }

    return true;
}

void add_list(Users_list& accounts, const std::vector<std::string>& list)
{
    assert(static_cast<int>(list.size()) == 2);
    
    if(entry_predicates(list))
    {
        accounts.add_to_list({list[0], list[1], "1"});
    }
}

void login(std::string& user_file,Users_list& accounts, 
            const std::vector<std::string>&list)
{
    assert(static_cast<int>(list.size()) == 2);

    if(entry_predicates(list))
    {
        user_file = accounts.get_item_from_list(Account({list[0], list[1]}))
        .get_credential().first;
    }
}

void deletion(Users_list& accounts, const std::vector<std::string>& list)
{
    assert(static_cast<int>(list.size()) == 2);

    if(entry_predicates(list))
    {
        accounts.remove_from_list(Account({list[0], list[1]}));
    }
}

void cli_control_flow(std::string& user_file, Users_list& accounts, 
                    boost::program_options::variables_map& vm,
                    boost::program_options::options_description& options)
{
    if(vm.count("create"))
    {
        add_list(accounts,vm["create"].as<std::vector<std::string>>());
    }
    if(vm.count("login"))
    {
        login(user_file, accounts, vm["login"].as<std::vector<std::string>>());
    }
    if(vm.count("delete"))
    {
        deletion(accounts,vm["delete"].as<std::vector<std::string>>());
    }
    if(vm.count("help"))
    {
        std::cout << options;
    }
}

std::string account_manager_cli(int argc, char** argv, const std::string& accounts_file)
{
    using namespace boost::program_options;

    Users_list accounts{};
    std::string user_file{};
    load_from_file<Users_list>(accounts_file, accounts);

    try
    {
        options_description options{"args"};
        options.add_options()
        ("login", value<std::vector<std::string>>()->composing()->multitoken()->zero_tokens(), "logs on an account")
        ("create", value<std::vector<std::string>>()->composing()->multitoken()->zero_tokens(), "creates an account")
        ("delete", value<std::vector<std::string>>()->composing()->multitoken(), "deletes an account")
        ("help", "shows all the commands");

        variables_map vm;
        store(parse_command_line(argc, argv, options),vm);
        notify(vm);
        cli_control_flow(user_file, accounts, vm, options);
    }
    catch(const error& excpt)
    {
        std::cerr << FEEDBACK_COLORS::BAD << excpt.what() 
                << " enter --help to see available commands\n"
                << FEEDBACK_COLORS::RESET;
    }

    save_to_file<Users_list>(accounts_file, accounts);
    return user_file;   
}