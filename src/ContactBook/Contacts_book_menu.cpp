#include <sstream>
#include <fstream>
#include <boost/program_options.hpp>

#include "Contacts_book_menu.h"
#include "Contacts_list.h"
#include "Contacts.h"
#include "../Utilities/io.h"

void search_contact(Contacts_list& list
    ,const std::vector<std::string>& fields)
{
    using namespace REGEX_PREDICATES;

    if(static_cast<int>(fields.size()) == 3)
    {
        if(arguments_verify(fields, {ALPHA_NOSPACE, DIGIT, EMAIL}))
        {
            std::cout << list.get_item_from_list
            (Contacts{fields[0], fields[1], fields[2]});
        }
        else
        {
            invalid_argument_error("--search");
        }
    }
    else
    {
        invalid_argument_quantity_error("--search", 3);
    }
}

void remove_contact(Contacts_list& list
    ,const std::vector<std::string>& fields)
{
    using namespace REGEX_PREDICATES;

    if(static_cast<int>(fields.size()) == 3)
    {
        if(arguments_verify(fields, {ALPHA_NOSPACE, DIGIT, EMAIL}))
        {
            list.remove_from_list(Contacts{fields[0], fields[1], fields[2]});
        }
        else
        {
            invalid_argument_error("--remove");
        }
    }
    else
    {
        invalid_argument_quantity_error("--remove", 3);
    }
}

void add_contact(Contacts_list& list
    ,const std::vector<std::string>& fields)
{
    using namespace REGEX_PREDICATES;

    if(static_cast<int>(fields.size()) == 3)
    {
        if(arguments_verify(fields, {ALPHA_NOSPACE, DIGIT, EMAIL}))
        {
            list.add_to_list(Contacts{fields[0], fields[1], fields[2]});
        }
        else
        {
            invalid_argument_error("--add");
        }
    }
    else
    {
        invalid_argument_quantity_error("--add", 3);
    }
}

void contacts_book_control_flow_cli(Contacts_list& list
            ,const boost::program_options::variables_map& vm
            ,const boost::program_options::options_description& option)
{
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
        add_contact(list, vm["add"].as<std::vector<std::string>>());
    }
    if(vm.count("remove"))
    {
        remove_contact(list, vm["remove"].as<std::vector<std::string>>());
    }
    if(vm.count("search"))
    {
        search_contact(list, vm["search"].as<std::vector<std::string>>());
    }
}

void contacts_book_cli(int argc, char** argv, const std::string& file_name)
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