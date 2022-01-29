#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <boost/program_options.hpp>
#include <regex>

#include "Users_list.h"
#include "Account_menu.h"
#include "../includes/io.h"
#include "../includes/extras.h"

void cli_control_flow(std::string& user_file, Users_list& accounts, 
                    boost::program_options::variables_map& vm,
                    boost::program_options::options_description& options)
{
    using namespace REGEX_PREDICATES;
    const auto PREDICATES = {ALPHA_NOSPACE, ALPHA_NOSPACE};
    const int EXPECTED_SIZE {2};

    if(vm.count("create"))
    {
        apply_function<Users_list>(vm["create"].as<std::vector<std::string>>()
            ,EXPECTED_SIZE, "--create", PREDICATES,[&](const auto& fields)
                {accounts.add_to_list({fields[0], fields[1], "1"});});
    }
    if(vm.count("login"))
    {
        user_file = apply_function<Users_list, std::string>
            (vm["login"].as<std::vector<std::string>>()
            ,EXPECTED_SIZE, "--login", PREDICATES
                ,[&](const auto& fields)
                {
                    return accounts.get_item_from_list
                    (Account{fields[0], fields[1]}).get_credential().first;
                });
    }
    if(vm.count("delete"))
    {
        apply_function<Users_list>(vm["delete"].as<std::vector<std::string>>()
            ,EXPECTED_SIZE, "--delete", PREDICATES, [&](const auto& fields)
                {accounts.remove_from_list(Account{fields[0], fields[1]});});
    }
    if(vm.count("help"))
    {
        std::cout << options;
    }
}

std::string account_manager_cli(int argc
                                ,char** argv
                                ,const std::string& accounts_file)
{
    using namespace boost::program_options;

    Users_list accounts        {};
    std::string user_file      {};
    load_from_file<Users_list> (accounts_file, accounts);

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
