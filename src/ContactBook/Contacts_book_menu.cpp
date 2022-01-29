#include <sstream>
#include <fstream>
#include <boost/program_options.hpp>

#include "Contacts_book_menu.h"
#include "Contacts_list.h"
#include "Contacts.h"
#include "../includes/io.h"
#include "../includes/extras.h"

void contacts_book_control_flow_cli(Contacts_list& list
            ,const boost::program_options::variables_map& vm
            ,const boost::program_options::options_description& option)
{
    using namespace REGEX_PREDICATES;

    const int  ARG_SIZE     {3};
    const auto predicates = {ALPHA_NOSPACE, DIGIT_NOSPACE, EMAIL};

    if(vm.count("help"))
    {
        std::cout << option;
    }
    if(vm.count("view"))
    {
        list.print_list();
    }
    if(vm.count("add"))
    {
        apply_function<Contacts_list>(vm["add"].as<std::vector<std::string>>(),
            ARG_SIZE , "--add", predicates, [&](const auto& fields)
            {list.add_to_list(Contacts{fields[0], fields[1], fields[2]});});
    }
    if(vm.count("remove"))
    {
        apply_function<Contacts_list>(vm["remove"].as<std::vector<std::string>>(),
            ARG_SIZE , "--remove", predicates, [&](const auto& fields)
            {list.remove_from_list(Contacts{fields[0], fields[1], fields[2]});});
    }
    if(vm.count("search"))
    {
        apply_function<Contacts_list>(vm["search"].as<std::vector<std::string>>(),
            ARG_SIZE , "--search", predicates, [&](const auto& fields)
            {std::cout << list.get_item_from_list(Contacts{fields[0], fields[1], fields[2]});});
    }
}

void contacts_book_cli(int argc
                    , char** argv
                    , const std::string& file_name)
{
    using namespace boost::program_options;

    Contacts_list contacts{};
    load_from_file<Contacts_list>(file_name, contacts);

    try
    {
        options_description options{"Options"};
        options.add_options()
        ("help", "show all available commands")
        ("remove", value<std::vector<std::string>>()->multitoken()->composing(),
        "removes a contact")
        ("add", value<std::vector<std::string>>()->multitoken()->composing(),
        "adds a new contact")
        ("search", value<std::vector<std::string>>()->multitoken()->composing(),
        "searches the database for the specific entry")
        ("view","shows all the available contacts");

        variables_map vm;
        store(parse_command_line(argc, argv, options), vm);
        notify(vm);
        contacts_book_control_flow_cli(contacts, vm, options);
    }
    catch(const error& excpt)
    {
        std::cerr << excpt.what() << '\n';
    }

    save_to_file<Contacts_list>(file_name, contacts);
}