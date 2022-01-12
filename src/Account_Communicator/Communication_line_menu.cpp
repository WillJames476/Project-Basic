#include <sstream>
#include <fstream>
#include <iomanip>
#include <boost/program_options.hpp>

#include "Communication_line.h"
#include "Communication_line_menu.h"
#include "../Utilities/io.h"

void access_account(std::string& file_name
                ,Communication_lines& com
                ,const std::vector<std::string>& arguments)
{
    using namespace REGEX_PREDICATES;

    if(static_cast<int>(arguments.size()) == 1)
    {
        if(arguments_verify(arguments, {ALPHA_NOSPACE}))
        {
            file_name = com.get_item_from_list(arguments[0]);
        }
        else
        {
            invalid_argument_error("--access");
        }
    }
    else
    {
        invalid_argument_quantity_error("--access", 1);
    }
}   

void alter_permission(const std::string& permanent_user
                    ,Communication_lines& comm
                    ,const std::vector<std::string>& arguments)
{
    using namespace REGEX_PREDICATES;

    if(static_cast<int>(arguments.size()) == 1)
    {
        if(arguments_verify(arguments, {ALPHA_NOSPACE}))
        {
            comm.alter_permission(permanent_user, arguments[0]);
        }
        else
        {
            invalid_argument_error("--alter");
        }
    }
    else
    {
        invalid_argument_quantity_error("--alter", 1);
    }
}

void remove_account(Communication_lines& comm,
                    const std::vector<std::string>& arguments)
{
    using namespace REGEX_PREDICATES;

    if(static_cast<int>(arguments.size()) == 1)
    {
        if(arguments_verify(arguments, {ALPHA_NOSPACE}))
        {
            comm.remove_from_list(arguments[0]);
        }
        else
        {
            invalid_argument_error("--delete");
        }
    }
    else
    {
        invalid_argument_quantity_error("--access", 1);
    }
}

void add_account(Communication_lines& comm, 
                const std::vector<std::string>& arguments)
{
    using namespace REGEX_PREDICATES;

    if(static_cast<int>(arguments.size()) == 1)
    {
        if(arguments_verify(arguments, {ALPHA_NOSPACE}))
        {
            comm.add_to_list(arguments[0], 0);
        }
        else
        {
            invalid_argument_error("--add");
        }
    }
    else
    {
        invalid_argument_quantity_error("--add", 1);
    }
}

void communication_line_cli_control(const std::string& permanent_user
                                    ,std::string& file_name
                                    ,Communication_lines& com
                                    ,boost::program_options::options_description& desc
                                    ,boost::program_options::variables_map& vm)
{
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
        add_account(com, vm["add"].as<std::vector<std::string>>());
    }
    if(vm.count("delete"))
    {
        remove_account(com, vm["delete"].as<std::vector<std::string>>());
    }
    if(vm.count("alter"))
    {
        alter_permission(permanent_user, com, vm["alter"].as<std::vector<std::string>>());
    }
    if(vm.count("access"))
    {
        access_account(file_name, com, vm["access"].as<std::vector<std::string>>());
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