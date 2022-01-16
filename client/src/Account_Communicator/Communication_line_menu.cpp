#include <sstream>
#include <fstream>
#include <iomanip>
#include <boost/program_options.hpp>

#include "Communication_line.h"
#include "Communication_line_menu.h"
#include "../includes/io.h"
#include "../includes/extras.h"

void communication_line_cli_control(const std::string& permanent_user
                                    ,std::string& file_name
                                    ,Communication_lines& com
                                    ,boost::program_options::options_description& desc
                                    ,boost::program_options::variables_map& vm)
{
    using namespace REGEX_PREDICATES;
    const int FIELDS_SIZE   {1};
    const auto PREDICATES = {ALPHA_NOSPACE};

    if(vm.count("help"))
    {
        std::cout << desc;
    }
    if(vm.count("view"))
    {
        std::cout << std::boolalpha << com;
    }
    if(vm.count("add"))
    {
        apply_function<Communication_lines>(vm["add"].as<std::vector<std::string>>(),
            FIELDS_SIZE, "--add", PREDICATES,[&](const auto& fields)
            {com.add_to_list(fields[0], 0);});
    }
    if(vm.count("delete"))
    {
        apply_function<Communication_lines>(vm["delete"].as<std::vector<std::string>>(),
            FIELDS_SIZE, "--delete", PREDICATES,[&](const auto& fields)
            {com.remove_from_list(fields[0]);});
    }
    if(vm.count("alter"))
    {
        apply_function<Communication_lines>(vm["alter"].as<std::vector<std::string>>(),
            FIELDS_SIZE, "--alter", PREDICATES,[&](const auto& fields)
            {com.alter_permission(permanent_user, fields[0]);});
    }
    if(vm.count("access"))
    {
        file_name = apply_function<Communication_lines, std::string>
                        (vm["access"].as<std::vector<std::string>>()
                        ,FIELDS_SIZE, "--access", PREDICATES, [&](const auto& fields)
                        {return com.get_item_from_list(fields[0]);});
    }
}

std::string communication_line_cli(int argc, char** argv, std::string& file_name)
{
    using namespace boost::program_options;

    Communication_lines comms        {};
    const std::string permanent_file {"users/" + file_name + "/" + file_name + "_comms.txt"},
                      permanent_user {file_name};

    comms.add_to_list(permanent_user, 1);
    load_from_file(permanent_file, comms);

    try
    {
        options_description description{"options"};
        description.add_options()
        ("help", "outputs all possible programs")
        ("view", "view all your communication lines")
        ("add", value<std::vector<std::string>>()->multitoken()->composing()->zero_tokens(), 
        "adds a new communication line")
        ("delete", value<std::vector<std::string>>()->multitoken()->composing()->zero_tokens(),
        "deletes a communication line")
        ("alter", value<std::vector<std::string>>()->multitoken()->composing()->zero_tokens(),
        "alers a permission")
        ("access", value<std::vector<std::string>>()->multitoken()->composing()->zero_tokens(),
        "access a permitted account");

        variables_map vm;
        store(parse_command_line(argc, argv, description), vm);
        notify(vm);
        communication_line_cli_control(permanent_user, file_name ,comms, description, vm);
    }
    catch(const error& excpt)
    {
        std::cerr << excpt.what() << '\n';
    }

    save_to_file(permanent_file, comms);
    return file_name;
}